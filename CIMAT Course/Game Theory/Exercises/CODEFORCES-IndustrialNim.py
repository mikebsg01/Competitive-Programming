from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
    for k in range(1, 10):
        print('-> %d: ' % k)
        for i in range(k, 20):
            x = 0
            for j in range(k, i + 1):
                x ^= j
            print('{:05b}'.format(x))
        print()

if __name__ == '__main__':
	main()
