from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

FACES = 6
T, N, K = 0, 0, 0
S = dict()

def backtrack(idx, totalSum):
	global FACES, N

	if idx == N:
		if totalSum in S:
			S[totalSum] += 1
		else:
			S[totalSum] = 1
		return

	for i in range(1, FACES + 1):
		backtrack(idx + 1, totalSum + i)

def main():
	global T, N, K, S
	T = readInt()

	for i in range(T):
		N, K = readInts()
		S = dict()
		backtrack(0, 0)

		total = sum([val for key, val in S.items()])
		print('Total:', total)

		for j in range(len(S)):
			print('{:3d}'.format(j), end= ' ')
		print()

		for key, val in S.items():
			print('{:3d}'.format(val), end=' ')
		print()

if __name__ == '__main__':
	main()
