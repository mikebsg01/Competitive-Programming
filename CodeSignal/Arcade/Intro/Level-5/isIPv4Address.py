def isIPv4Address(s):
	try:
		l = list(map(int, s.split('.')))
		n = len(l)
		return n == 4 and all(x >= 0 and x <= 255 for x in l)
	except:
		return False

def main():
	print(isIPv4Address('172.16.254.1'))
	print(isIPv4Address('172.316.254.1'))
	print(isIPv4Address('.254.255.0'))
	print(isIPv4Address('1.256.1.1'))

if __name__ == '__main__':
	main()
