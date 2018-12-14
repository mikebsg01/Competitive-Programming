import sys

def readInt():
	return int(sys.stdin.readline())

def readInts():
	return list(map(int, sys.stdin.readline().split()))

def readLine():
	return sys.stdin.readline().split()[0]

def stdPrint(m):
	sys.stdout.write((str(m) if type(m) is int else m) + "\n")
	sys.stdout.flush()

def stdPrintErr(m):
	sys.stderr.write(">" + (str(m) if type(m) is int else m) + "\n")

def binary(a, b, n):

	while a < b:
		m = int((a + b) / 2)
		stdPrint(m)
		
		x = readLine()

		if x == 'CORRECT':
			return
		elif x == 'TOO_SMALL':
			a = m + 1
		elif x == 'TOO_BIG':
			b = m
		elif x == 'WRONG_ANSWER':
			sys.exit(0)
			return

	m = int((a + b) / 2)
	stdPrint(m)
	x = readLine()

	if x == 'WRONG_ANSWER':
		sys.exit(0)
	return


def main():
	t = readInt()
	
	for i in range(t):
		a, b = readInts()
		n = readInt()
		binary(a, b, n)

if __name__ == '__main__':
	main()
