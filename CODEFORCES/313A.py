from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
    N = readLine()
    A = int(N)
    B = int(N[:-1])
    C = int(N[:-2] + N[-1:])
    print(max(A, B, C))

if __name__ == '__main__':
	main()