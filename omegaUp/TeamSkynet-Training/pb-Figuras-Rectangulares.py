from math import sqrt

def readLine():
	return raw_input()

def readInt():
	return int(readLine())

def is_square(n):
	root = int(sqrt(n))
	
	return (root * root) == n

def is_rectangle(n):
	i = 2

	while i * i < n:
		if (n % i) == 0:
			return True
			break
		i += 1

	return False
		

def main():
	n = readInt()

	if is_square(n) and is_rectangle(n):
		print('ambos')
	elif is_square(n):
		print('cuadrado')
	else:
		print('rectangulo')

if __name__ == '__main__':
	main()
