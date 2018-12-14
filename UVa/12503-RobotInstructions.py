from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	T = readInt()
	move = lambda x: -1 if x == 'LEFT' else (1 if x == 'RIGHT' else 0)

	for i in range(T):
		N = readInt()
		action = [None for j in range(N)]
		p = 0

		for j in range(N):
			action[j] = readLine()

			k = j
			while True:
				m = move(action[k])

				if m != 0:
					p += m
					break
				else:
					a, b, c = action[k].split()
					k = int(c) - 1

		print(p)
					

if __name__ == '__main__':
	main()
