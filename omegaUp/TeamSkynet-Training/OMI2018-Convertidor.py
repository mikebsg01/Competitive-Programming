def readLine():
	return str(raw_input())

def readInt():
	return int(readLine())

def toDecimal(str):
	str = str[::-1]
	s = 0
	p = 1

	for c in str:
		s += p * (ord(c) - 64)
		p *= 26
	return s
		

def toStr(n):
	s = ""

	while n > 0:
		r = (n - 1) % 26
		s = chr(65 + r) + s
		n = (n - r - 1) // 26

	return s

def main():
	t = readInt()

	if t:
		s = readLine()
		print(str(toDecimal(s)))
	else:
		n = readInt()
		print(toStr(n))

if __name__ == '__main__':
	main()
