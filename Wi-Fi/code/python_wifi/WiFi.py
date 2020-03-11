import socket

s = socket.socket()
data = []
s.bind(('0.0.0.0', 8091))
s.listen(0)

while True:

    client, addr = s.accept()

    while True:
        content = client.recv(4096)

        if len(content) == 0:
            break

        else:
            #print(content)
            data += content.decode('utf-8')
            #data.append(content)


    print("Closing connection")
    # data = list
    #outdata = data.splitlines()
    #SR_row = pd.Series(outdata)
    #DF = DF.append(SR_row, ignore_index=True)
    print(data)
    client.close()
