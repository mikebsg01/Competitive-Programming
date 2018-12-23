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
	k = 0
	while True:
		k += 1

		try:
			S = readLine()
			M = len(S)
		except:
			break

		if M == 0:
			break

		A = [0 for i in range(M + 1)]

		for i in range(1, M + 1):
			A[i] = A[i - 1] + int(S[i - 1])

		Q = readInt()
		print('Case %d:' % k)

		for i in range(Q):
			i, j = readInts()
			i, j = min(i, j) + 1, max(i, j) + 1
			diff = A[j] - A[i - 1]
			dist = j - i + 1

			print('%s' %('Yes' if diff == dist or diff == 0 else 'No'))

if __name__ == '__main__':
	main()
