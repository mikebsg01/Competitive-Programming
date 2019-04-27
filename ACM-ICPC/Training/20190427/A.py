from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	N, X = readInts()
	A = readInts()
	A.sort()
	ans = 1 if len(A) > 0 else 0

	for i in range(1, len(A)):
		if (A[i - 1] + A[i]) > X:
			break
		
		ans += 1

	print(ans)

if __name__ == '__main__':
	main()