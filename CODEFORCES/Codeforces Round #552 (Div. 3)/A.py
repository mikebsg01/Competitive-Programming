from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	w, x, y, z = sorted(readInts())
	print((z - y), (z - x), (z - w))

if __name__ == '__main__':
	main()
