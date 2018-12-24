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
	vertical = ['+x', '+y', '-x', '-y']
	horizontal = ['+x', '+z', '-x', '-z']

	isY = lambda s: s.endswith('y')
	isPosY = lambda s: s == '+y'
	isNegY = lambda s: s == '-y'

	isZ = lambda s: s.endswith('z')
	isPosZ = lambda s: s == '+z'
	isNegZ = lambda s: s == '-z'

	isNo = lambda s: s == 'No'

	while True:
		try:
			L = readInt()

			if L == 0:
				break
		except:
			break

		A = readLine().split()
		current = '+x'
		
		for a in A:
			if isNo(a):
				continue

			if a in vertical and current in vertical:

				if isPosY(a):
					current = vertical[(vertical.index(current) + 1) % len(vertical)]
				elif isNegY(a):
					current = vertical[vertical.index(current) - 1]

			elif a in horizontal and current in horizontal:

				if isPosZ(a):
					current = horizontal[(horizontal.index(current) + 1) % len(vertical)]
				elif isNegZ(a):
					current = horizontal[horizontal.index(current) - 1]

		print(current)

if __name__ == '__main__':
	main()
