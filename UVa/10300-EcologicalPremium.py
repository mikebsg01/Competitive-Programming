from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	n = readInt()

	for i in range(n):
		f = readInt()
		ans = 0

		for j in range(f):
			s, a, e = readInts()
			ans += (s * e)

		print(ans)

if __name__ == '__main__':
	main()
