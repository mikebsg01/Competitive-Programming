from sys import stdin

def readLine():
	return stdin.readline()

def readInt():
	return int(readLine())

N = 0
A = []

def main():
	global N, A
	N = readInt()
	A = [0 for i in range(N)]

	for i in range(N):
		if i > 1:
			A[i] = A[i - 1] + A[i - 2]
		elif i == 0:
			A[i] = 2
		elif i == 1:
			A[i] = 3

	print(A[N - 1])	

if __name__ == '__main__':
	main()
