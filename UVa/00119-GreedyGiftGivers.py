from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def dd(**args):
	print(args)

def main():
	k = 0
	while True:
		try:
			N = readInt()
		except:
			break

		names = readLine().split()
		given = dict()

		for name in names:
			given[name] = 0

		for i in range(N):
			line = readLine().split()
			giver_name = line[0]
			money = int(line[1])
			p = int(line[2])
			people_names = line[3 : 3 + p]
			x = int(money // p) if p != 0 else 0

			for person_name in people_names:
				given[person_name] += x

			given[giver_name] -= p * x

		if k > 0:
			print()

		for key, val in given.items():
			print('%s %d' %(key, val))
		k += 1

if __name__ == '__main__':
	main()
