from sys import stdin
from functools import reduce

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def f(n):
	n = list(str(n))
	return reduce(lambda x, y: int(x) + int(y), n)

def g(n):
	while n != f(n):
		n = f(n)
	return n

def main():
	while True:
		n = readInt()

		if n == 0:
			break

		print(g(n))

if __name__ == '__main__':
	main()
