from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	T = readInt()

	for i in range(T):
		N = readInt()
		A = readInts()
		h, l = 0, 0

		for j in range(1, N):
			if A[j - 1] < A[j]:
				h += 1
			elif A[j - 1] > A[j]:
				l += 1

		print('Case %d: %d %d' %(i + 1, h, l))

if __name__ == '__main__':
	main()
