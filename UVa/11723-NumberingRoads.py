from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

def main():
	k = 0
	while True:
		k += 1
		N, R = readInts()

		if N == R == 0:
			break

		solution = -1

		for i in range(27):
			if N <= (R + (R * i)):
				solution = i
				break

		print('Case {}: {}'.format(k, 'impossible' if solution == -1 else solution))

if __name__ == '__main__':
	main()
