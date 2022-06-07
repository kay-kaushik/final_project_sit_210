import serial
import string
import time
import requests
#opeing serial port
ser=serial.Serial('/dev/ttyACM0',9600)
#it can different in your case like
while True:
    serialdata=ser.readline()
    print(serialdata)
    
    #print(type(serialdata))
    value = int(serialdata[:3])
    #print(int(value))
    if(value > 200):
        url = 'https://maker.ifttt.com/trigger/gas_detected/json/with/key/f8WLVvakcjufz_dh25sqWM86m6i3VtAEaLnGQFrs564'
        values = {"value1":"none","value2":"none","value3":"none"}
        r = requests.post(url, data = values)
        print(r.text)
        time.sleep(20)
    #read serial data and print it on screen