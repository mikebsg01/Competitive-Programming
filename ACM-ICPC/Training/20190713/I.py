from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

MAXPOWER = 1000

def winner(N, H, V, T):
    for i in range(N):
        h = H[i] + T
        v = V[i]
    
        if h > v:
            return 1
        elif v > h:
            return -1

    return 0

def main():
    N = readInt()
    H = readInts()
    V = readInts()

    for i in range(MAXPOWER + 1):
        if winner(N, H, V, i) != -1:
            print(i)
            break

if __name__ == '__main__':
	main()