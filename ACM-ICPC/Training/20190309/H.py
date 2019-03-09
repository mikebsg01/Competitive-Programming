from sys import stdin
from collections import Set

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	S = readLine()
	N = len(S)
	E = readInt()
	L = [set() for i in range(E)]
	A = [False for i in range(E)]
	
	for i in range(E):
		l = readLine().split()

		for e in l:
			L[i].add(e)

		for j in range(N):
			A[i] = S[j : N] in L[i]

			if A[i]:
				break

	P = readInt()

	for i in range(P):
		p = readLine()
		m = len(p)
		solved = False

		for j in range(E):
			for k in range(m):
				t = p[m - k - 1 : m]

				if str.startswith(t, ' '):
					break

				if (t in L[j]) and A[j]:
					solved = True

			if solved:
				break

		print('YES' if solved else 'NO')

if __name__ == '__main__':
	main()
