from sys import stdin

MOV_Y = [-1, 0, 1]
n, m = 0, 0
t = []
minWeight = []
currentPath = []
ans = None
shortestPath = None
complexity = 0

def wrap(y):
	return n - 1 if y < 0 else 0 if y >= n else y  

def search(y, x, w):
	global ans, shortestPath, complexity

	w += t[y][x]

	if (not minWeight[y][x] is None) and (w > minWeight[y][x]):
		return
	elif minWeight[y][x] is None:
		minWeight[y][x] = w

	currentPath.append(y + 1)
	complexity += 1

	if x == (m - 1):
		if ans is None or w < ans:
			ans = w
			shortestPath = list(currentPath)
	else:
		for ym in MOV_Y:
			search(wrap(y + ym), x + 1, w)
	
	currentPath.pop()


def main():
	global n, m, t, ans, shortestPath, minWeight, complexity
	
	while True:
		ans = None
		shortestPath = None
		line = stdin.readline()
		sp = line.split()
		
		if not line or line == '' or len(sp) == 0:
			break

		n, m = map(int, sp)

		minWeight = [[None for j in range(0, m)] for i in range(0, n)] 
		t = [[None for j in range(0, m)] for i in range(0, n)]
		li = []
		
		while len(li) < (n * m):
			li = li + list(map(int, stdin.readline().split()))

		k = 0

		for i in range(0, n):
			for j in range(0, m):
				t[i][j] = li[k]
				k += 1

		for i in range(0, n):
			search(i, 0, 0)

		print(*shortestPath)
		print(ans)
		# print("complexity: " + str(complexity))

if __name__ == '__main__':
	main()
