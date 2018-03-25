from sys import stdin

def readNum():
	return int(stdin.readline())

def readNums():
	return list(map(int, stdin.readline().split()))

def main():
	i = 1

	while True:
		ans = 0
		n = readNum()
	
		if n == 0:
			break

		for v in readNums():
			ans = ans + (-1 if v == 0 else 1)

		print('Case %d: %d' %(i, ans))
		i = i + 1

if __name__ == '__main__':
	main()
