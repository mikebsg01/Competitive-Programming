def readLine():
	return raw_input()

def is_rotation(b, a):
	for i in range(len(a)):
		if a[i:] + a[:i] == b:
			return True
	return False
			

def main():
	a = readLine()
	b = readLine()

	print("Rotacion" if is_rotation(b, a) else "No rotacion")

if __name__ == '__main__':
	main()
