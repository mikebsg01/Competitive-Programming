from sys import stdin

def readLine():
    return stdin.readline().strip()

def readInt():
    return int(readLine())

def readInts():
    return list(map(int, readLine().split()))

def main():
	T = readInt()

	for i in range(T):
		S = readLine()
		P = readLine()
		A = [S.index(i) for i in P]
		A.sort()
		ans = ''
		
		for i in A:
			ans += S[i]
		
		print(ans)
            
if __name__ == '__main__':
	main()