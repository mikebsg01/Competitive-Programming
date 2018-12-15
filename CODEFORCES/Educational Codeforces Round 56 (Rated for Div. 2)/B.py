from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

T, S = 0, None

def main():
	global T, S
	T = readInt()

	for i in range(T):
		S = list(readLine())
		n = len(S)
		isImpossible = all(S[i] == S[0] for i in range(n))

		if isImpossible:
			print('-1')
		else:
			while True:
				if S != S[::-1]:
					print(''.join(S))
					break
				else:
					for j in range(1, n):
						if S[j] != S[0]:
							S[0], S[j] = S[j], S[0]
							break

if __name__ == '__main__':
	main()
