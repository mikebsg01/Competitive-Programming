from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def isSolution(l):
	n = len(l)

	if n < 2:
		return False

	for i in range(1, n):
		if l[i - 1] >= l[i]:
			return False

	return True

def divide(N, S):
	m = N // 2
	for k in range(1, m + 1):
		prev = int(S[:k])
		res = [prev]

		i, last, taken = k, k, ''
		while i < N:
			while i < N:
				taken += S[i]
				i += 1
				val = int(taken)

				if val > prev:
					prev = val
					res.append(prev)
					taken = ''
					last = i
					break

		if last < N:
			res[-1] = int(str(res[-1]) + S[last:])

		if isSolution(res):
			return (True, res)

	return (False, None)

def main():
	Q = readInt()

	for i in range(Q):
		N = readInt()
		S = readLine()
		t = divide(N, S)

		if t[0]:
			print('YES')
			print(len(t[1]))
			print(' '.join(map(str, t[1])))
		else:
			print('NO')

if __name__ == '__main__':
	main()
