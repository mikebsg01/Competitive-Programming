from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

def main():
	while True:
		try:
			C = readInts()
			X = readInts()
			N = len(C)
			M = len(X)

			if N == 0:
				break
		except:
			break

		for i in range(M):
			s = sum(C[j] * X[i] ** (N - j - 1) for j in range(N))

			if i > 0:
				print(end=' ')

			print(s, end='')
		print()
				

if __name__ == '__main__':
	main()
