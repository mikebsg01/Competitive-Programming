from sys import stdin

def readLine():
	return stdin.readline().split()[0]

def main():
	i = 1
	while True:
		word = readLine()

		if word == '*':
			break

		print('Case %d: %s' %(i, 'Hajj-e-Akbar' if word == 'Hajj' else 'Hajj-e-Asghar'))
		i += 1

if __name__ == '__main__':
	main()
