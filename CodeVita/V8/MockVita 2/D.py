from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

T, N = 0, 0

def main():
    N = readInt()
    T = readInt()
    A = [readInts() for i in range(N)]
    D = [0 for i in range(N)]
    W = [0 for i in range(N)]

    i = 0
    while i < T:
        best = -1
        partialWinner = 0

        for j in range(N):
            D[j] += (A[j][i] + A[j][i + 1]) * A[j][-1]

            if D[j] > best:
                best = D[j]
                partialWinner = j
                
        W[partialWinner] += 1
        i += 2

    best = -1
    winner = 0

    for i in range(N):
        if W[i] > best:
            best = W[i]
            winner = i

    print(winner + 1)


if __name__ == '__main__':
	main()
