def readLine():
	return raw_input()

def readInts():
	return list(map(int, readLine().split()))

def main():
	a, b, c = readInts()

	if c >= a and c <= b:
		print("INTERVALO")
	elif c < a:
		print("IZQUIERDA")
	else:
		print("DERECHA")


if __name__ == '__main__':
	main()
