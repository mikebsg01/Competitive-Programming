from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def main():
	N = readInt()

	for i in range(N):
		S = readLine()
		M, ans = len(S), False
		
		for j in range(M):
			for k in range(M):
				if j != k and S[j] == S[k]:
					ans = True

		print('Yes' if ans else 'No')

if __name__ == '__main__':
	main()
