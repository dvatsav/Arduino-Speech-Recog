import string
import serial
def takeinput(filename):
	f = open(filename,'r')
	a = f.read()
	return a.lstrip("*")
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
	a = checkoperation(takeinput('sm2.txt'))
	#s = serial.Serial('12C',9600)
	#s.write('HELLO')
	#s.write(a)\
	print (a)

	
