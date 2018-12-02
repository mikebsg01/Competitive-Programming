from sys import stdin

def readLine():
	return stdin.readline()

def readInt():
	return int(readLine())

def main():
	i = 1
	while True:
		n = readInt()

		if n == 0:
			break

		print('%d. %s %d' %(i, 'even' if n % 2 == 0 else 'odd', n // 2))
		i += 1
		

if __name__ == '__main__':
	main()
