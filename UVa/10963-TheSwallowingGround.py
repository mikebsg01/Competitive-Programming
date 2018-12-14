from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	t = readInt()

	for i in range(t):
		readLine()
		w = readInt()
		canBeClosed = True

		for j in range(w):
			n, s = readInts()

			if j == 0:
				diff = n - s
			elif (n - s) != diff:
				canBeClosed = False

		if i > 0:
			print()	

		print('yes' if canBeClosed else 'no')

if __name__ == '__main__':
	main()
