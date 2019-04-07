from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

T, N = 0, 0

def main():
    T = readInt()

    for i in range(1, T + 1):
        N = readLine()
        A = int(N.replace('4', '1'))
        B = int(N) - A
        print('Case #%d: %d %d' %(i, A, B))

if __name__ == '__main__':
	main()
