from sys import stdin

def readint():
    return int(stdin.readline())

def main():
    n = readint()
    print((-1 if n % 2 else 1) * int((n + 1) / 2))

if __name__ == '__main__':
    main()