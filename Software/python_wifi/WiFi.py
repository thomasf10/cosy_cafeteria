import socket
import schedule
import time
import numpy as np

s = socket.socket()
s.bind(('0.0.0.0', 8091))
s.listen(0)

def processdata(data):
    '''Todo: update data in the sql database'''
    #list with amgpixels
    amgpixels = []
    #todo: receive other sensor data and save it

    for idx in range(64):
        #convert uint8's to float
        raw_unit8_data = np.array([data[4*idx], data[4*idx+1], data[4*idx+2], data[4*idx+3]], dtype='uint8')
        temp = raw_unit8_data.view('<f4')
        amgpixels.append(temp)
    for pixel in amgpixels:
        print(pixel)



def listen():
    data = []
    client, addr = s.accept()
    print('connected to: ', addr)
    timeout = False
    while True:
        try:
            client.settimeout(5)
            content = client.recv(4096)
        except socket.timeout:
            timeout = True
            break
        if len(content) == 0:
            break
        else:
            data += content
    if not timeout:
        print(data)
        processdata(data)
    else:
        print('timeout')
    print("Closing connection")
    client.close()

#raw_unit8_data = np.array([0, 0, 162, 65], dtype='uint8')

while True:
    listen()

