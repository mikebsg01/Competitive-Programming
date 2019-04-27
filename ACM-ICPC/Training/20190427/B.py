from sys import stdin
from datetime import datetime as dt, timedelta

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def daysBetween(d1, d2):
	y1 = '2018' if d1 > d2 else '2019'
	y2 = '2019'

	d1 = dt.strptime('%s-%s' % (y1, d1), '%Y-%m-%d')
	d2 = dt.strptime('%s-%s' % (y2, d2), '%Y-%m-%d')
	return abs((d2 - d1).days)

def yesterday(d):
	d = dt.strptime('2019-%s' % d, '%Y-%m-%d')
	y = d - timedelta(days=1)
	return y.strftime('%m-%d')

def getIdx(N, A):
	for i in range(N):
		if A[i] > '10-28':
			return i
	return 0

def main():
	N = readInt()
	A = [None for i in range(N)]

	for i in range(N):
		s, d = readLine().split(' ')
		A[i] = d

	A.sort()
	idx = getIdx(N, A)
	longest = daysBetween(A[idx - 1], A[idx])
	ans = A[idx]

	i = (idx + 1) % N
	while i != idx:
		res = daysBetween(A[i - 1], A[i])

		if res > longest:
			longest = res
			ans = A[i]
		
		i = (i + 1) % N

	print(yesterday(ans))

if __name__ == '__main__':
	main()