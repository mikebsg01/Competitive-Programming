from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dist(a, b):
	return min((26 + ord(a) - ord(b)) % 26, (26 + ord(b) - ord(a)) % 26)

def calc(S):
	res = dist(S[0], 'A')
	res += dist(S[1], 'C')
	res += dist(S[2], 'T')
	res += dist(S[3], 'G')
	return res

def solve(N, S):
	ans = 4 * 26
	for i in range(N - 3):
		c = calc(S[i : i + 4])
		ans = min(ans, c)
	return ans
		

def main():
	N = readInt()
	S = readLine()
	print(solve(N, S))

if __name__ == '__main__':
	main()
