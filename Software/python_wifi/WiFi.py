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
    amgpixels = [] #in °C
    amgtemp = 0 #in °C
    audio = 0 # in volts, maybe convert to db
    co2_level = 0 # in ppm
    TVOC_level = 0 #in ppb (tvoc = total volatile organic compounds)

    #todo: receive other sensor data and save it

    #proces amg pixels
    for idx in range(64):
        #convert uint8's to float
        raw_unit8_data = np.array([data[4*idx], data[4*idx+1], data[4*idx+2], data[4*idx+3]], dtype='uint8')
        temp = raw_unit8_data.view('<f4')
        amgpixels.append(temp)
    #proces amg temp
    raw_unit8_data = np.array([data[4*64], data[4*64+1], data[4*64+2], data[4*64+3]], dtype='uint8')
    amgtemp = raw_unit8_data.view('<f4')

    #proces audio level
    raw_unit8_data = np.array([data[4*65], data[4*65+1], data[4*65+2], data[4*65+3]], dtype='uint8')
    audio = raw_unit8_data.view('<f4')

    #proces co2 level
    raw_unit8_data = np.array([data[4*66], data[4*66+1]], dtype='uint8')
    co2_level = raw_unit8_data.view('uint16')

    #proces co2 level
    raw_unit8_data = np.array([data[4*66+2], data[4*66+3]], dtype='uint8')
    TVOC_level = raw_unit8_data.view('uint16')

    #todo proces co2
    for pixel in amgpixels:
        print(pixel)
    print("amgtemp: ")
    print(amgtemp)
    print("audio ")
    print(audio)
    print("co2 level: ")
    print(co2_level)
    print("TVOC level: ")
    print(TVOC_level)


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
       # print(data)
        processdata(data)
    else:
        print('timeout')
    print("Closing connection")
    client.close()

#raw_unit8_data = np.array([0, 0, 162, 65], dtype='uint8')

while True:
    listen()

