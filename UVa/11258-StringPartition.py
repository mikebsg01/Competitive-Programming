from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

INT_MAX = 2147483647
UNVISITED = -1
N, S, M = 0, '', 0
DP = []

def dp(idx):
	global INT_MAX, S, M

	if idx == M:
		return 0

	if DP[idx] != UNVISITED:
		return DP[idx]

	for i in range(idx, M):
		val = int(S[idx : i + 1])

		if (val > INT_MAX):
			break

		DP[idx] = max(DP[idx], val + dp(i + 1))

	return DP[idx]

def main():
	global N, S, M, DP, UNVISITED
	N = readInt()

	for i in range(N):
		S = readLine()
		M = len(S)
		DP = [UNVISITED for j in range(M)]
		print(dp(0))

if __name__ == '__main__':
	main()
