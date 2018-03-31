from sys import stdin
from decimal import Decimal

def readInt():
	return int(stdin.readline())

def readInts():
	return list(map(int, stdin.readline().split()))

def main():
	t = readInt()

	for i in range(t):
		D, N = readInts()
		slowest = 0
		
		for j in range(N):
			K, S = readInts()

			dist = D - K
			minTime = Decimal(dist) / S
			slowest = max(slowest, minTime)

		print("Case #" + str(i + 1) + ":", round((Decimal(D) / slowest), 6))

if __name__ == '__main__':
	main()
