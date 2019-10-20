from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
    N = readInt()
    S = [i for i in range(1, N + 1)]
    
    for i in range(N - 1, 0, -1):
        S.append(i)

    M = len(S)
    ans = [0 for i in range(M)]
    carry = 0

    for i in range(M):
        S[i] += carry
        carry = int(S[i] // 10)
        ans[i] = (S[i] % 10)

    print(''.join(map(lambda x: str(x), ans[::-1])))

if __name__ == '__main__':
	main()
