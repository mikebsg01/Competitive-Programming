from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

def main():
	t = 0
	while True:
		t += 1
		N, M, C = readInts()

		if N == M == C == 0:
			break

		A = [readInt() for i in range(N)]
		isOn = [False for i in range(N)]
		power, maxPower, isBlown = 0, 0, False

		for i in range(M):
			idx = readInt() - 1
			power += A[idx] * (1 if not isOn[idx] else -1)
			isOn[idx] ^= True
			maxPower = max(maxPower, power)

			if power > C:
				isBlown = True

		if isBlown:
			print('Sequence %d\nFuse was blown.\n' % (t))
		else:
			print('Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n' %(t, maxPower))
			

if __name__ == '__main__':
	main()
