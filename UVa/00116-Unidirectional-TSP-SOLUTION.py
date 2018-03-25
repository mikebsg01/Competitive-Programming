from sys import stdin

def readNumbers():
	return list(map(int, stdin.readline().split()))

MOV_Y = [-1, 0, 1]
n, m, = 0, 0
t = []
dp = []
shortestPath = []

def wrap(y):
	global n
	return (y + n) % n

def neighboor(y, x):
	global dp

	if x >= 0:
		w = dp[y][x]

		if w is not None:
			return w
	return 0

def main():
	global n, m, t, dp, ans, shortestPath

	while True:
		try:
			n, m = readNumbers()
		except ValueError:
			return

		shortestPath = []

		li = []

		while len(li) < (n * m):
			li.extend(readNumbers())

		t = [li[(m * i):(m * (i +1))] for i in range(0, n)]
		dp = [[None for j in range(0, m)] for i in range(0, n)]
		source = [[None for j in range(0, m)] for i in range(0, n)]

		for i in range(0, n):
			dp[i][0] = t[i][0]
			source[i][0] = [ dp[i][0], (i + 1) ]

		for j in range(1, m):
			for i in range(0, n):
				dp[i][j] = t[i][j]

				w, path = None, None

				for ym in MOV_Y:
					yt = wrap(i + ym)
					wt = neighboor(yt, j - 1)

					if w is None or wt < w or (wt == w and source[yt][j-1][1:] < path):
						w = wt
						path = source[yt][j-1][1:]

				dp[i][j] += w
				source[i][j] = [ dp[i][j] ] + path + [i + 1]

		shortestPath = min([source[i][m - 1] for i in range(0, n)])

		print(*shortestPath[1:])
		print(shortestPath[0])

if __name__ == '__main__':
	main()
