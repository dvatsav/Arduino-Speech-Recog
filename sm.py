import string
import serial
import bluetooth
def takeinput():
	arduino = serial.Serial('COM3', 9600, timeout=.1)
	while True:
		data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
		newdata = data.decode()
		if newdata:
			return (newdata)
def checkoperation(a):
	if '+' in a or 'add' in a or 'plus' in a:
		return add(a)
	elif '-' in a or 'minus' in a or 'subtract' in a:
		return subtract(a)
	elif 'x' in a or 'multiply' in a or 'times' in a:
		 return multiply(a)
	elif 'divided' in a or 'divide' in a:
		 return divide(a)
def add(a):
	newL=[int(s) for s in a.split() if s.isdigit()]
	return (sum(newL))
def subtract(a):
	newL=[int(s) for s in a.split() if s.isdigit()]
	if 'subtract' in a:
		return (newL[1] - newL[0])
	else:
		return (newL[0] - newL[1])
def multiply(a):
	newL=[int(s) for s in a.split() if s.isdigit()]
	return (newL[0] * newL[1])
def divide(a):
	newL=[int(s) for s in a.split() if s.isdigit()]
	return (newL[0] / newL[1])
if __name__=='__main__':
	a = takeinput()
	b = checkoperation(a)

	#s = serial.Serial('12C',9600)
	#s.write('HELLO')
	#s.write(a)\
	print (b)

	
