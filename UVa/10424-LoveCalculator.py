from sys import stdin
from decimal import Decimal as dec

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

filterAlphas = lambda s: list(filter(lambda c: c.isalpha(), list(s)))
getVal = lambda c: ord(c) - (ord('a') if 'a' <= c <= 'z' else ord('A')) + 1
toValues = lambda l: list(map(lambda c: getVal(c), l))

def convertToOneDigit(l):
	while True:
		s = str(sum(l))

		if len(s) == 1:
			break

		l = list(map(int, list(s)))

	return dec(s)

def main():
	while True:
		try:
			A = toValues(filterAlphas(readLine()))
			B = toValues(filterAlphas(readLine()))
		except:
			break

		if len(A) == 0:
			break

		A = convertToOneDigit(A)
		B = convertToOneDigit(B)
		A, B = min(A, B), max(A, B)
		print('%1.2f %%' % (A / B * 100))

if __name__ == '__main__':
	main()
