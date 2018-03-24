from sys import stdin

def main():
	leftQuote = False

	while True:
		c = stdin.read(1)
		if not c:
			break
		
		if c != '"':
			print(c, end='')
		else:
			if leftQuote:
				leftQuote = False
				print("''", end='')
			else:
				leftQuote = True
				print("``", end='')
		

if __name__ == '__main__':
	main()
