from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

INT_MAX = 2147483647
N, S, M = 0, '', 0
P, ans = [], 0

def backtrack(idx):
	global INT_MAX, S, M, P, ans

	if idx == M:
		ans = max(ans, sum(P))
		return

	for i in range(idx, M):
		val = int(S[idx : i + 1])

		if (val > INT_MAX):
			break

		P.append(val)
		backtrack(i + 1)
		P.pop()

def main():
	global N, S, M, ans
	N = readInt()

	for i in range(N):
		ans = 0
		S = readLine()
		M = len(S)
		backtrack(0)
		print(ans)

if __name__ == '__main__':
	main()
