from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def solve(N, T):
	S = T[0]
	A = T[0] if T[0] != 'a' else ''
	B = ''

	for i in range(1, N):
		B += T[i]

	if A == B:
		return S
	
	for i in range(1, N):
		A += T[i] if T[i] != 'a' else ''
		
		if A == B[i:]:
			return T[:i + 1]
	
	return False


def main():
	T = readLine()
	N = len(T)
	ans = solve(N, T)
	print(':(' if ans == False else ans)

if __name__ == '__main__':
	main()