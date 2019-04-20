from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def count(c, S):
	res = 0
	for e in S:
		if c == e:
			res += 1
	return res

def main():
	S = readLine()
	N = len(S)
	M = count('a', S)
	
	if M > (N / 2):
		print(N)
	else:
		print(2 * M - 1)

if __name__ == '__main__':
	main()