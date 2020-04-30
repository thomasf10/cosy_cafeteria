import socket
import schedule
import time
import numpy as np
import mysql.connector #pip3 install mysql-connector
import json

s = socket.socket()
s.bind(('0.0.0.0', 8091))
s.listen(0)

#mseting up data base connection
mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="root",
    database="cossycafetaria"
)

mycursor = mydb.cursor()

def processdata(data):
    '''Todo: update data in the sql database'''
    #list with amgpixels
    amgpixels = [] #in °C
    amgtemp = 0 #in °C
    audio = 0 # in volts, maybe convert to db
    co2_level = 0 # in ppm
    TVOC_level = 0 #in ppb (tvoc = total volatile organic compounds)
    sensor_id = 0 #the id of the sensor

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

    #proces sensor_id
    sensor_id = data[4*66+4]

    # #making dummy data
    # for i in range(64):
    #     amgpixels.append(i+20.25)
    # amgtemp = 21.55
    # audio = 0.84
    # co2_level = 33
    # TVOC_level = 44

    #print data
    print(amgpixels)
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
    print("sensor id: ")
    print(sensor_id)



    #writing away the data to the database:
    #the query used to insert the data
    sqlInsertReading="INSERT INTO readings (date, amgtemp, co2_level, TVOC_level, audio, infraredreading, sensor_id) VALUES (NOW(), %s, %s, %s, %s, %s, %s)" 

    #filling in the query, converting the list with pixels into a json object
    val = (amgtemp, co2_level, TVOC_level, audio, json.dumps(list(amgpixels)), sensor_id)
    
    #executing and commiting to finallise the pushing to the db
    mycursor.execute(sqlInsertReading, val)
    mydb.commit()



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

while True:
    listen()

