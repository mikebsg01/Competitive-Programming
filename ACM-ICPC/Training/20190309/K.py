from sys import stdin
from math import factorial as fact
from decimal import Decimal as dec

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

der = []

def countDer(n):
	global der
	der = [dec('0') for i in range(n + 3)]
	der[0] = dec('1')
	der[1] = dec('0')
	der[2] = dec('1')

	for i in range(3, n + 1):
		der[i] = dec(i - 1) * (der[i - 1] + der[i - 2])

	return der[n]


def main():
	N = readInt()

	if N <= 12:
		der = countDer(N)
		f = fact(N)
		res = (f - der) / f
		print('%.8f' % res)
	else:
		print('0.63212056')

if __name__ == '__main__':
	main()
