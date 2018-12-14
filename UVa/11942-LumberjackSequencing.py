from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	N = readInt()

	print('Lumberjacks:')

	for i in range(N):
		A = readInts()

		if 	all(A[i - 1] < A[i] for i in range(1, len(A))) or \
			all(A[i - 1] > A[i] for i in range(1, len(A))):
			print('Ordered')
		else:
			print('Unordered')

if __name__ == '__main__':
	main()
