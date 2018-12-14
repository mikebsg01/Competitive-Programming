from sys import stdin
from math import ceil

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	N = readInt()
	song = 'Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you'
	song = song.split()
	M = len(song)
	R = ceil(N / M)
	name = [None for i in range(N)]

	for i in range(N):
		name[i] = readLine()

	k = 0
	for i in range(R):
		for j in range(M):
			print('%s: %s' %(name[k], song[j]))
			k = (k + 1) % N

if __name__ == '__main__':
	main()
