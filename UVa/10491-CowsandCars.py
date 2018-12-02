from sys import stdin
from decimal import Decimal

def readLine():
	return stdin.readline()

def readDecimals():
	return list(map(Decimal, readLine().split()))

def main():
	while True:
		try:
			v, a, m = readDecimals()
		except:
			break

		w = (a - 1) * a + a * v
		l = (v - m) * a + (v - m - 1) * v
		t = w + l
		p = w / t
		print('%.5f' % p)

if __name__ == '__main__':
	main()
