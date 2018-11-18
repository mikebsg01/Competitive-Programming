from sys import stdin

def readLine():
	return stdin.readline()

def readInt():
	return int(readLine())

MAXM = 75
DP = [0 for i in range(MAXM)]

def getFactors(n):
	f = 0

	if n >= 1:
		f += 1

	i = 2
	while i * i <= n:
		if (n % i) == 0:
			if (i * i) == n:
				f += 1
			else:
				f += 2
		i += 1

	if n > 1:
		f += 1

	return f
		

def precalculate():
	DP[0] = DP[1] = 1

	for i in range(2, MAXM - 4):
		DP[i] = i * DP[i - 1] + (i - 1) * DP[i - 2]

def main():
	t = readInt()
	precalculate()

	for i in range(t):
		n = readInt()
		f = getFactors(n)

		if f > 0:
			print(DP[f - 1])
		else:
			print('0')

if __name__ == '__main__':
	main()
