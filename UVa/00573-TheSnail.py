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

def main():
	while True:
		H, U, D, F = readDecimals()

		if H == 0:
			break

		F = (U * F) / 100
		day = 0
		current = 0
		success = False

		while current >= 0 and current <= H:
			day += 1
			current += U

			if current > H:
				success = True
				break

			current -= D
			U = max(0, U - F)

		print('%s on day %d' %('success' if success else 'failure', day))

if __name__ == '__main__':
	main()
