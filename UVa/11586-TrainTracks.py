from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

T, N, M = 0, 0, 0
P = []
ans = set()

def backtrack(idx):
	if idx >= M:
		solution = True
		i = 1

		while i < M:
			if P[i] == P[(i + 1) % M]:
				solution = False
				break
			i += 2

		if solution:
			Q = []

			for i in range(0, M, 2):
				Q.append(P[i] + P[i + 1])

			Q.sort()
			ans.add(''.join(Q))
		return
	
	P.append('M')
	backtrack(idx + 1)
	P.pop()
	P.append('F')
	backtrack(idx + 1)
	P.pop()

def isLoop(a):
	s = ''.join(a)

	if s.count('M') != s.count('F'):
		return False

	i = 0
	j = len(a) - 1

	while i < j:
		if (not (a[i] == 'FF' and a[j] == 'MM')) and a[i] != a[j]:
			return not any(x != 'MF' and x != 'FM' for x in a[i : j + 1])

		i += 1
		j -= 1

	return True

def main():
	global T, N, M, ans

	T = readInt()

	for i in range(T):
		'''
		N = readInt()
		M = 2 * N
		ans = set()
		backtrack(0)

		for x in ans:
			for j in range(0, len(x), 2):
				print(x[j] + x[j + 1], end=' ')
			print()
		print()
		'''

		A = sorted(readLine().split())
		# print(A)
		print('LOOP' if len(A) != 1 and isLoop(A) else 'NO LOOP')

if __name__ == '__main__':
	main()
