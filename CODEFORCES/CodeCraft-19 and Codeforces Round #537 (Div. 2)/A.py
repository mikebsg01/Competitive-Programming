from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

isVowel = lambda c: c in ('a', 'e', 'i', 'o', 'u')

def isEqual(s, t):
	n = len(s)

	if n != len(t):
		return False

	for i in range(n):
		if isVowel(s[i]) != isVowel(t[i]):
			return False

	return True

def main():
	S = readLine()
	T = readLine()
	print('Yes' if isEqual(S, T) else 'No')

if __name__ == '__main__':
	main()
