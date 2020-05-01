
import socket
import schedule
import time

s = socket.socket()
s.bind(('0.0.0.0', 8091))
s.listen(0)

def processdata(data):
    '''Todo: update data in the sql database'''
    for dat in data:
        print(dat)

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
    else:
        print('timeout')
    print("Closing connection")
    client.close()

while True:
    listen()

