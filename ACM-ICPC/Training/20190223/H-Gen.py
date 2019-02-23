from sys import stdin
from random import randint

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	N = 20
	print(N)

	for i in range(N):
		for j in range(3):
			print(randint(0, 23), end=' ')
		print(randint(0, 13))
		

if __name__ == '__main__':
	main()
