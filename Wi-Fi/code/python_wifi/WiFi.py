import socket

s = socket.socket()

s.bind(('0.0.0.0', 8091))
s.listen(0)

while True:
    data = []
    client, addr = s.accept()
    while True:
        content = client.recv(4096)
        if len(content) == 0:  # no data received
            break
        else:  # received byte is stored in content
            data += content   # add received byte to data
    print("received data: ")
    print(data)
    #received data is stored in 'data'
    #todo manipulate and publish the data to the SQL database
    print("Closing connection")
    client.close()
