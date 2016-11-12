import serial
import bluetooth
arduino = serial.Serial('COM3', 9600, timeout=.1)
while True:
	data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
	newdata = data.decode()
	if newdata:
		print (newdata)