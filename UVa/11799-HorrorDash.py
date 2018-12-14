from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	T = readInt()

	for i in range(T):
		c = readInts()
		ans = max(c[1:])
		print('Case %d: %d' %(i + 1, ans))

if __name__ == '__main__':
	main()
