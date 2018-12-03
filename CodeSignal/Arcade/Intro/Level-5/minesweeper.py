MOV_Y = [-1, -1, 0, 1, 1,  1,  0, -1]
MOV_X = [ 0,  1, 1, 1, 0, -1, -1, -1]

def minesweeper(matrix):
	N, M, P = len(matrix), len(matrix[0]), len(MOV_Y)
	res = [[0 for j in range(M)] for i in range(N)]

	for i in range(N):
		for j in range(M):
			if matrix[i][j]:
				for k in range(P):
					y = i + MOV_Y[k]
					x = j + MOV_X[k]

					if y < 0 or y >= N or x < 0 or x >= M:
						continue

					res[y][x] += 1
	return res

def main():
	matrix = [[True, False, False],
		  [False, True, False],
		  [False, False, False]]

	ans = minesweeper(matrix)

	for r in ans:
		print(r)

if __name__ == '__main__':
	main()
