from sys import stdin

def readLine():
	return stdin.readline()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def toIntList(s):
	return list(map(int, s.split()))

M, N = 0, 0

def main():
	while True:
		try:
			M, N = readInts()
		except:
			break

		src = [[] for i in range(M)]

		for i in range(M):
			a = readInts()
			r = a[0]
			b = readInts()

			for j in range(r):
				tmp = (a[j + 1], b[j])
				src[i].append(tmp)

		dest = [[] for i in range(N)]

		for i in range(len(src)):
			for j in range(len(src[i])):
				tmp = (i + 1, src[i][j][1])

				dest[src[i][j][0] - 1].append(tmp)

		print('%d %d' %(N, M))
	

		for i in range(N):
			r = len(dest[i])
	
			print(r, end='')

			for j in range(r):
				print(' %d' %(dest[i][j][0]), end='')

			print()

			if r == 0:
				print()
			else:
				for j in range(r):
					if j > 0:
						print(' ', end='')

					print('%d' %(dest[i][j][1]), end='')

				print()

if __name__ == '__main__':
	main()
