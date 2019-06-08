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
	print(N)

if __name__ == '__main__':
	main()