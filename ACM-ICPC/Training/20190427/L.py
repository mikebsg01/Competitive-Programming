from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def getVal(e):
	return e[0]

def main():
	A = list(map(getVal, readLine().split(' ')))
	A.sort()
	equal = 0
	ans = 0
	
	for i in range(len(A)):
		if i == 0:
			prev = A[i]
			equal = 1
		else:
			if prev == A[i]:
				equal += 1
			else:
				prev = A[i]
				equal = 1

		ans = max(ans, equal)
	
	print(ans)
		

if __name__ == '__main__':
	main()