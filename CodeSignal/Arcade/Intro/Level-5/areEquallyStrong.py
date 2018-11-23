def areEquallyStrong(a,b,c,d):
	p, q = [a, b], [c, d]
	return any(p[0] == q[j] and p[1] == q[j ^ 1] for j in range(2))

def main():
	print(areEquallyStrong(10, 15, 15, 10))
	print(areEquallyStrong(15, 10, 15, 10))
	print(areEquallyStrong(15, 10, 15, 9))

if __name__ == '__main__':
	main()
