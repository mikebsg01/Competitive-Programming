from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

N = 0
A = []
C = 0

def isValid(num):
    global A, N, C
    num = str(num)
    for digit in A:
        if str(digit) in num:
            return False
    return True

def main():
    global A, N, C
    A = readInts()
    N = A[0]
    A = A[1:]
    C = readInt()
    ans = 999
    
    for i in range(1000):
        if (isValid(i)):
            res = abs(C - i)
            ans = min(ans, res)

    print(ans)

if __name__ == '__main__':
	main()