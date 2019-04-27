from sys import stdin
from datetime import datetime as dt, timedelta
from math import sqrt, cos, radians

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	A, B, C, D = readInts()
	S = (A + B + C + D) / 2
	K = sqrt((S - A) * (S - B) * (S - C) * (S - D))
	print('%.15f' % K)

if __name__ == '__main__':
	main()