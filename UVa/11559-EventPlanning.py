from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	while True:
		try:
			N, B, H, W = readInts()
		except:
			break

		ans = 500199

		for i in range(H):
			p = readInt()
			capacity = readInts()

			if max(capacity) >= N:
				ans = min(ans, N * p)

		print(ans if ans <= B else 'stay home')
	

if __name__ == '__main__':
	main()
