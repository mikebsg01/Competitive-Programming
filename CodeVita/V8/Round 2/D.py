from sys import stdin
from math import factorial as fact

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

comb = lambda n, k: int(fact(n) / (fact(k) * fact(n - k)))
R, N = 0, 0
A = []
LA = 0

def f(m, idx):
    global R, N, A, LA 

    if idx >= LA:
        return 1

    x = A[idx]

    if m % (N - idx - 1) != 0:
        return comb(m, x) * f(m - x, idx + 1)
    else:
        return comb(m, (N - idx - 1))


def main():
    global R, N, A, LA
    R, N = readInts()
    D = int(N / R)
    M = N

    for i in range(0, R - 1):
        A.append(D)
        M -= D
    
    A.append(M)
    A.reverse()
    LA = len(A)

    ans = f(N, 0)
    print(ans)

if __name__ == '__main__':
	main()
