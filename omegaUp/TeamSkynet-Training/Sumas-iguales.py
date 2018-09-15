def readLine():
	return raw_input()

def readInt():
	return int(readLine())

def gaussSum(n):
	return (n * (n + 1)) // 2

def findBalance(n):
	a = 0
	b = n - 1
	m = (a + b) // 2
	left = gaussSum(m)
        right = gaussSum(n) - (m + 1) - left

	while left != right:
		m = (a + b) // 2
		left = gaussSum(m)
                right = gaussSum(n) - (m + 1) - left

		if left > right:
			b = m
		elif left < right:
			a = m + 1

	return (m + 1, n)

def main():
	n = readInt()
	print(' '.join(map(str, findBalance(n))))

if __name__ == '__main__':
	main()
