def readLine():
	return raw_input()

def readInt():
	return int(readLine())

def main():
	t = readInt()

	for i in range(t):
		s = sorted(readLine())
		s.reverse()
		s = ''.join(s)
		a = int(s[:-1])
		b = int(s[-1])

		print(str(a + b))
			

if __name__ == '__main__':
	main()
