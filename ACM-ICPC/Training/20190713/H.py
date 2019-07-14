from sys import stdin
from math import pi

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
    A, P1 = readInts()
    R, P2 = readInts()
    print('Whole pizza' if (A * 1.0 / P1) < ((pi * R * R) / P2) else 'Slice of pizza')

if __name__ == '__main__':
	main()