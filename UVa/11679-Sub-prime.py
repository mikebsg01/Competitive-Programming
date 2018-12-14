from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	while True:
		B, N = readInts()

		if B == 0 and N == 0:
			break

		A = readInts()

		for i in range(N):
			d, c, v = readInts()
			A[d - 1] -= v
			A[c - 1] += v

		print('N' if any(x < 0 for x in A) else 'S')

if __name__ == '__main__':
	main()
