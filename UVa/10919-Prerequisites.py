from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

K, M = 0, 0
A = []

def readSelectedCourses(k):
	l = []

	for i in range(K):
		t = readInts()
		l.extend(t)

		if len(l) >= k:
			return l

meet = lambda r, s: sum(c in s for c in A) >= r

def main():
	global K, M, A

	while True:
		try:
			K, M = readInts()
		except:
			break

		A = readSelectedCourses(K)
		solution = True

		for i in range(M):
			t = readInts()
			c = t[0]
			r = t[1]
			s = frozenset(t[2:])

			if not meet(r, s):
				solution = False

		print('yes' if solution else 'no')

if __name__ == '__main__':
	main()
