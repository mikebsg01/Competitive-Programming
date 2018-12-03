from sys import stdin

def readLine():
	return stdin.readline()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

T, N = 0, 0
A = []

getX = lambda t: t[0]
getY = lambda t: t[1]

def getArea(x1, y1, x2, y2):
	w = abs(x2 - x1)
	h = abs(y2 - y1)
	m = max(w, h)
	return m ** 2

def main():
	global T, N, A
	T = readInt()

	for i in range(T):
		N = readInt()
		A = [None for i in range(N)] 

		for j in range(N):
			A[j] = tuple(readInts())

		minX = min(A, key = getX)[0]
		maxX = max(A, key = getX)[0]
		minY = min(A, key = getY)[1]
		maxY = max(A, key = getY)[1]
		area = getArea(minX, minY, maxX, maxY)
		print(area)

if __name__ == '__main__':
	main()
