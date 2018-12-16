from sys import stdin
from decimal import Decimal as dec

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def readDecimals():
	return list(map(dec, readLine().split()))

def dd(**args):
	print(args)

N, P = 0, 0

def main():
	global N, P
	t = 0
	while True:
		t += 1
		N, P = readInts()

		if N == P == 0:
			break

		R = [readLine() for i in range(N)]
		compliance, supplier = 0, ''

		for i in range(P):
			name = readLine()
			price, r = readDecimals()
			r = int(r)

			for j in range(r):
				req_name = readLine()

			if i == 0 or ((r > compliance) or (r == compliance and price < bestPrice)):
				compliance = r
				bestPrice = price
				supplier = name

		if t > 1:
			print()

		print('RFP #%d\n%s' %(t, supplier))

if __name__ == '__main__':
	main()
