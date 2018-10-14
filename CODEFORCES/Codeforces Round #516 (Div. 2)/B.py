from sys import stdin

def readLine():
	return stdin.readline()

def readInt():
	return int(readLine())

f = lambda a, x: a - (a ^ x) - x

def main():
	n = readInt()

	for i in range(n):
		a = readInt()
		bn = bin(a)[2:]
		ans = 1

		for i in bn:
			if i == '1':
				ans *= 2

		print(ans)
	

if __name__ == '__main__':
	main()
