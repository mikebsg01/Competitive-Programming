from sys import stdin
from math import ceil

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	T = readInt()
	mile = lambda x: ceil((x + 1) / 30) * 10
	juice = lambda x: ceil((x + 1) / 60) * 15

	for i in range(T):
		N = readInt()
		A = readInts()
		m, j = 0, 0

		for x in A:
			m += mile(x)
			j += juice(x)


		ans = 'Case %d: ' %(i + 1)

		if m < j:
			ans += 'Mile %d' %(m)
		elif j < m:
			ans += 'Juice %d' %(j)
		else:
			ans += 'Mile Juice %d' %(m)

		print(ans)

if __name__ == '__main__':
	main()
