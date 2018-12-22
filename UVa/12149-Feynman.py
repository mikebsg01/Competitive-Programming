from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

f = lambda n: ((2 * n ** 3) + (3  * n ** 2) + n)  // 6

def main():
	while True:
		N = readInt()

		if N == 0:
			break

		print(f(N))

if __name__ == '__main__':
	main()
