from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

T, N = 0, 0

def main():
	T = readInt()

	for i in range(T):
		N, K = readInts()
		C = int(N // K)
		R = N % K
		S = ''

		for j in range(K):
			S += chr(ord('a') + j) * C

		if R != 0:
			S += chr(ord('a') + j) * R

		print(S)

if __name__ == '__main__':
	main()
