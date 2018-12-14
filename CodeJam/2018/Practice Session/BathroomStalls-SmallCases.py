from sys import stdin

def readInt():
	return int(stdin.readline())

def readInts():
	return list(map(int, stdin.readline().split()))

def calc(a, pos):
	posL  = pos - 1
	posR = pos + 1

	while not a[posL]:
		posL -= 1

	while not a[posR]:
		posR += 1

	L = pos - posL - 1
	R = posR - pos - 1

	return [max(L, R), min(L, R)]

def main():
	t = readInt()

	for i in range(t):
		N, K = readInts()

		A = [1] + [0 for i in range(N)] + [1]
		
		for k in range(K):
			minDis = 0
			maxDis = 0
			ansPos = 0

			for j in range(N + 1, 1, -1):
				if not A[j]:
					x = calc(A, j)

					if (x[1] > minDis) or (x[1] == minDis and x[0] > maxDis):
						minDis = x[1]
						maxDis = x[0]
						ansPos = j
			A[ansPos] = 1

			if k == K - 1:
				print("Case #" + str(i + 1) + ":", maxDis, minDis)

if __name__ == '__main__':
	main()
