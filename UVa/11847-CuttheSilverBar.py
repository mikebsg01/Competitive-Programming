from sys import stdin
from math import floor, log

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def main():
	while True:
		N = readInt()

		if N == 0:
			break

		print(floor(log(N, 2)))

if __name__ == '__main__':
	main()
