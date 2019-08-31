from sys import stdin
from math import gcd

def readLine():
    return stdin.readline().strip()

def readInt():
    return int(readLine())

def readInts():
    return list(map(int, readLine().split()))

def main():
    n = readInt()
    bills = [100, 20, 10, 5, 1]
    ans = 0

    for bill in bills:
        if n >= bill:
            d = n // bill
            ans += d
            n -= d * bill

    print(ans)

if __name__ == '__main__':
    main()
