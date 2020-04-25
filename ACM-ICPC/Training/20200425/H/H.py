from sys import stdin
from math import sqrt

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def readFloats():
	return list(map(float, readLine().split()))

f = lambda x: 3 * (((x - 1) * x) // 2) + 2 * x

def main():
    H = readInt()
    while f(H) % 4 != 0:
        H += 1
    print(H)

if __name__ == '__main__':
	main()