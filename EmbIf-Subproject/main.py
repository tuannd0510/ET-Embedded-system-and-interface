# import os

# class Parking():

#     def ReadRFID(self):
#         dev = os.open("/dev/rfid_rc522_dev", os.O_RDONLY)
#         while (self.rfid != None and self.rfid !=0 ):
#             self.rfid = os.read(dev,4)
#         os.close(dev)

#     def Display_Lcd(self,text):
#         dev = os.open("dev/lcd",os.O_WRONLY)
#         os.write(dev,text)
#         os.close(dev)

    
# SHOW DATABASES;
# USE nhung;
# DESCRIBE nhung;
# 
# wgiILQ69

import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="wgiILQ69",
    database="htn"
)    
print(mydb)