import socket
import time

# bind all IP
HOST = '192.168.1.11'
BROADCASTIP = "192.168.1.255"
# Listen on Port
PORT = 8093
#MESSAGE = "Hello, World!"
string = "yeet"

# string with encoding 'utf-8'
arr = bytes(string, 'utf-8')
# Create a UDp socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)


while True:

    print('sending message')

    s.sendto(arr , (BROADCASTIP, PORT))
    time.sleep(1)
# Close connection
s.close()