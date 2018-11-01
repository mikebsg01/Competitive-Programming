def readLine():
	return raw_input().strip()

def binToInt(b):
	return int(b, 2)
	
def main():
	a = binToInt(readLine())
	b = binToInt(readLine())
	c = bin(a * b)
	print(c[2:])


if __name__ == '__main__':
	main()
