from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def allEqual(D, N, A):
	for e in A:
		if e != A[0] and abs(e - A[0]) != D:
			return False
	return True

def isSolution(D, N, A):
	if allEqual(D, N, A):
		return True

	A[0] += D

	if allEqual(D, N, A):
		return True

	A[0] -= 2 * D
	
	if allEqual(D, N, A):
		return True

	A[0] += D

	return False

def solve(N, A):
	for D in range(0, 101):
		if isSolution(D, N, A):
			return D
	return -1

def main():
	N = readInt()
	A = readInts()
	print(solve(N, A))

if __name__ == '__main__':
	main()
