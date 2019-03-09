from sys import stdin
from decimal import Decimal as dec

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def readDecimal():
	return dec(readLine())

def readDecimals():
	return list(map(dec, readLine().split()))

def main():
	C = readDecimal()
	L = readInt()
	ans = dec('0.0')

	for i in range(L):
		A = readDecimals()
		ans += A[0] * A[1] * C

	print('%.7f' % ans)

if __name__ == '__main__':
	main()
