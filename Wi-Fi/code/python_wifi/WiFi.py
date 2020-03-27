#import socket
'''
s = socket.socket()
s.bind(('', 8291))
s.listen(0)
i = 0
while True:
    i += 1
    print(i)
    data = []
    client, addr = s.accept()
    while True:
        print(i)
        content = client.recv(4096)
        if not content:  # no data received => break from the while
            break
        else:  # received byte is stored in content
            data += content   # add received byte to data
    print("received data: ")
    print(data)
    #received data is stored in 'data'
    #todo manipulate and publish the data to the SQL database
    print("Closing connection")
    client.close()
'''
'''
HOST = ''  # Symbolic name meaning all available interfaces
PORT = 8291  # Arbitrary non-privileged port
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen(1)
    while True:
        conn, addr = s.accept()
        dataarray = []
        print('Connected by', addr)
        while True:
            data = conn.recv(320)
            if len(data) == 0:
                break
            dataarray += data
        print(dataarray)
        conn.close()
'''
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

