from sys import stdin
from random import randint

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLin().split()))

MAXN = 17
MAXVAL = 33

def main():
	N = randint(0, MAXN);
	print(N)

	for i in range(N):
		val = randint(-1 * MAXVAL, MAXVAL);
		print(val, end=' ')

	print()

	M = randint(0, MAXN)
	print(M)

	for i in range(M):
		a = randint(1, N)
		b = randint(a, N)
		print(a, b)

if __name__ == '__main__':
	main()
