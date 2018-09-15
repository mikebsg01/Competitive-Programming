def readLine():
	return raw_input()

def readInt():
	return int(readLine())

def f(n):
	return (n * n) + (2 * n) + 3

def main():
	n = readInt()
	print(str(f(n - 1)))

if __name__ == '__main__':
	main()
