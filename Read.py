from email import header
import json
from operator import index
from statistics import mode
import serial
from time import sleep
import datetime
import pandas as pd
import os

for i in range(0,255):
    try:
        com = f"COM{i}"
        ser = serial.Serial(com,9600,timeout=0.2)
        break
    except Exception as e:
        com = 0
        pass
    
def loadF(data):
    dte = datetime.datetime.now().date()
    Fname = f"{dte}.txt"
    try:
        f = open(Fname,"a")
        st = json.dumps(data)+"\n"
        f.write(st)
        f.close()
        return True
    except Exception as e:
        print(e)
        return False
print(com)

flag = True
while flag:
    try:
        strd = ser.readline().decode('utf-8')
        # print(strd)
        
        if '{"t":' in strd:
            # print(strd)
            dct = json.loads(strd)
            dt = str(datetime.datetime.now())
            dct['Time'] =dt
            if loadF(dct):print(dct)
    except Exception as e:
        print(e)
        # if loadF({"Error":str(e),}," error"):print({"Error":e})
        sleep(1)
