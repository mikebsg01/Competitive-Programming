from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def main():
	n = readInt()

	for i in range(n):
		s = readLine()

		if s == '1' or s == '4' or s == '78':
			print('+')
		elif s.endswith('35'):
			print('-')
		elif s.startswith('9') and s.endswith('4'):
			print('*')
		elif s.startswith('190'):
			print('?')

if __name__ == '__main__':
	main()
