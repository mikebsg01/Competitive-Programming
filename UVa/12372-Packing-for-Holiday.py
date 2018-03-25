from sys import stdin

def readNum():
	return int(stdin.readline())

def readNums():
	return list(map(int, stdin.readline().split()))

def main():
	t = readNum()

	for i in range(1, t + 1):
		l, w, h = readNums()

		print('Case %d: %s' %(i, ('good' if (l <= 20 and w <= 20 and h <= 20) else 'bad')))

if __name__ == '__main__':
	main()
