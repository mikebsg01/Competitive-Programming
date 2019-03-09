from sys import stdin
from collections import Counter
from math import floor, log

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

A = []
C = Counter()

def isPowerOfTen(n):
	if n == 0 or n % 10 != 0:
		return False

	return True if n == 10 else isPowerOfTen(n // 10)

def solve():
	global C
	D = Counter()
	solved = False

	num = 0
	add = 1
	while True:
		num += add
		isPower = isPowerOfTen(num)
		add = add * 10 if isPower else add
		id = num // add

		if isPower:
			D[0] += 1

			if C[0] < D[0]:
				return num
		
		D[id] += 1
		# print(num, id, isPower, C[id], D[id])

		if C[id] < D[id]:
			return str(id) * D[id]

def main():
	global A, C
	S = readLine()
	A = sorted(list(map(int, list(S))))

	for e in A:
		C[e] += 1

	print(solve())

if __name__ == '__main__':
	main()
