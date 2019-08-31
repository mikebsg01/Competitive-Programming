from sys import stdin
from math import gcd

def readLine():
    return stdin.readline().strip()

def readInt():
    return int(readLine())

def readInts():
    return list(map(int, readLine().split()))

MAX_POINTS = 6

def main():
    global MAX_POINTS
    y, w = readInts()
    b = MAX_POINTS
    a = MAX_POINTS - max(y, w) + 1
    g = gcd(a, b)
    a /= g
    b /= g
    print('%d/%d' %(a, b))

if __name__ == '__main__':
    main()
