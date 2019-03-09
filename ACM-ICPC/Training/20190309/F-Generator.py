from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	s = ''
	for j in range(100):
		for i in range(10):
			s += str(i)
	print(s)

if __name__ == '__main__':
	main()
