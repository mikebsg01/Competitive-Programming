from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

MOD = int(1e9 + 7)

def getOddSum(a, b):
	return ((b * (b + 1)) - b) - ((a * (a + 1)) - a)

def getEvenSum(a, b):
	return (b * (b + 1)) - (a * (a + 1))

def getSum(isOdd, a, b):
	return getOddSum(a, b) if isOdd else getEvenSum(a, b)

isInside = lambda x, a, b: a <= x <= b
getIdx = lambda n: 0 if n == 0 else getIdx(n >> 2) + n
getIndex = lambda n: getIdx(n >> 2)
mod = lambda n: n % MOD
modSum = lambda a, b: mod(mod(a) + mod(b))
modSub = lambda a, b: mod(mod(a) - mod(b))

def solve(L, R):
	isOdd = 1
	currentPos = [2, 1]
	p = 1
	s = 0
	subtract = 0
	res = 0

	while not isInside(L, p, (p << 1) - 1):
		currentPos[isOdd] <<= 2
		p <<= 1
		isOdd ^= 1

	if p < L:
		s = getSum(isOdd, getIndex(currentPos[isOdd]), getIndex(currentPos[isOdd]) + (L - p))
		subtract = modSum(subtract, s)

	while p <= R:
		s = getSum(isOdd, getIndex(currentPos[isOdd]), getIndex(currentPos[isOdd]) + currentPos[isOdd])
		currentPos[isOdd] <<= 2
		res = modSum(res, s)
		p <<= 1
		isOdd ^= 1

	if R < (p - 1):
		p >>= 1
		isOdd ^= 1
		currentPos[isOdd] >>= 2
		s = getSum(isOdd, getIndex(currentPos[isOdd]) + (R - p + 1), getIndex(currentPos[isOdd]) + currentPos[isOdd])
		subtract = modSum(subtract, s)
	
	return modSub(res, subtract)

def main():
	global MOD
	L, R = readInts()
	print(solve(L, R))

if __name__ == '__main__':
	main()