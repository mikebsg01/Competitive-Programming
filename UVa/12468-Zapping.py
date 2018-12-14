from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	while True:
		a, b = readInts()

		if a == -1 and b == -1:
			break

		limit = 100
		p = max(a, b) - min(a, b)
		q = limit - max(a, b) + min(a, b)
		print(min(p, q))

if __name__ == '__main__':
	main()
