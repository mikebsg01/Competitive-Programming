from sys import stdin

def readNum():
	return int(stdin.readline())

def main():
	account = 0
	n = readNum()

	for i in range(0, n):
		line = list(stdin.readline().split())
		op = line[0]

		if op == 'donate':
			amount = int(line[1])
			account += amount
		else:
			print(account)

if __name__ == '__main__':
	main()
