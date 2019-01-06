from sys import stdin

def readLine():
	return stdin.readline()

def readInt():
	return int(readLine())

MAXN = 11
cat = [1 for i in range(MAXN)]

def catalan():
	global MAXN, cat
	
	for i in range(1, MAXN):
		cat[i] = int((((2 * i) * (2 * i - 1)) / ((i + 1) * i)) * cat[i - 1])
	
def main():
	global cat
	catalan()

	t = 0
	while True:
		t += 1

		try:
			N = readInt()
			readLine()
		except:
			break

		if t > 1:
			print()
	
		print(cat[N])

if __name__ == '__main__':
	main()
