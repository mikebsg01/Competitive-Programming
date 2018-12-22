from sys import stdin
from math import sqrt, floor

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

f = lambda x: floor((-1 + sqrt(1 + 8 * x)) / 2)

def main():
	T = readInt()

	for i in range(T):
		N = readInt()
		print(f(N))

if __name__ == '__main__':
	main()
