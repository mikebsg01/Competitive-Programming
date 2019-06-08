from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

gaussSum = lambda n: (n * (n + 1)) // 2;

'''
def solve(X, Y):
    A = Y - 1
    B = X + A
    C = gaussSum(B)
    D = (B - Y) if B % 2 else (Y - 1)
    ans = C - D
    return ans
'''

solve = lambda X, Y: gaussSum(X + Y - 1) - (X - 1) * ((X + Y - 1) & 1) - (Y - 1) * (((X + Y - 1) & 1) ^ 1)

def main():
    while True:
        X, Y = readInts()

        if X == Y == 0:
            break

        print(solve(X, Y))

if __name__ == '__main__':
	main()
