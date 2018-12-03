from sys import stdin

def readLine():
	return stdin.readline()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

N, M = 0, 0
A = []
B = []
NOT_FOUND = -1

def binary(x):
	global N, A
	a, b = 0, N - 1

	while a < b:
		m = (a + b) // 2

		if A[m] < x:
			a = m + 1
		else:
			b = m
	
	if A[a] >= x:
		return a

	return NOT_FOUND

def main():
	global N, M, A

	N = readInt()
	A = readInts()
	M = readInt()

	for i in range(1, N):
		A[i] += A[i - 1]
	
	for j in range(M):
		x = readInt()
		i = binary(x)
		print(i if i is NOT_FOUND else (i + 1))
	

if __name__ == '__main__':
	main()
