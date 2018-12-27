from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

T, N = 0, 0

def main():
	N = readInt()
	S = readLine()

	i = 1
	j = 0
	while j < N:
		print(S[j], end='')
		j += i
		i += 1
	print()

if __name__ == '__main__':
	main()
