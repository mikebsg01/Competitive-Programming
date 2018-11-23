def boxBlur(t):
	n, m = len(t) - 2, len(t[0]) - 2
	r = [[0 for j in range(m)] for i in range(n)]
	for i in range(n):
		for j in range(m):
			v = sum([sum(r[j : j + 3]) for r in t[i : i + 3]]) // 9
			r[i][j] = v
	return r

def main():
	image = [[7, 4, 0, 1], 
		 [5, 6, 2, 2],
		 [6, 10, 7, 8],
		 [1, 4, 2, 0]]

	ans = boxBlur(image)
	print(ans)

	image =	[[36,0,18,9], 
		 [27,54,9,0], 
		 [81,63,72,45]]

	ans = boxBlur(image)
	print(ans)

if __name__ == '__main__':
	main()

