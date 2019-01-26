from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

# f = lambda k, x: 1 + 9 * (k - 1) + (x - 1)
f = lambda k, x: 9 * k - 9 + x

def main():
	N = readInt()

	for i in range(N):
		K, X = readInts()
		print(f(K, X))

if __name__ == '__main__':
	main()
