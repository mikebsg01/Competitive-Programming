from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

LETTERS = ord('z') - ord('a') + 1
toNum = lambda x: ord(x) - ord('a')
toChar = lambda x: chr(x + ord('a'))

def main():
	T, N = readInts()
	S = [None for i in range(T)]

	for i in range(T):
		S[i] = readLine()

	ans = [None] * N

	for j in range(N):
		counter = [0] * LETTERS

		for i in range(T):
			counter[toNum(S[i][j])] += 1

		maxCounter, letter = -1, None

		for i in range(LETTERS):
			if counter[i] > maxCounter:
				maxCounter, letter = counter[i], toChar(i)

		ans[j] = letter

	print(''.join(ans))

if __name__ == '__main__':
	main()
