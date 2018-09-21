def readLine():
	return raw_input()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def isPalindrome(n, a):
	if a[0] == 0:
		return False

	i = 0
	j = n - 1

	while i < j:
		if a[i] != a[j]:
			return False
		i += 1
		j -= 1

	return True
		

def main():
	n = readInt()
	a = readInts()

	print('SI' if isPalindrome(n,  a) else 'NO')	

if __name__ == '__main__':
	main()
