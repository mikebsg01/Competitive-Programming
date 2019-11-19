from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def generateSequence():
    s = ''

    for i in range(1, 371):
        s += str(i)

    return s

def main():
    s = generateSequence()
    n = readInt()
    print('EVEN' if int(s[n - 1]) % 2 == 0 else 'ODD')

if __name__ == '__main__':
    main()