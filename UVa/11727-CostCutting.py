def main():
	n = int(input())

	for i in range(0, n):
		a = list(map(int, input().split()))
		a.sort()
		print('Case %s: %d' %(i + 1, a[1]))

if __name__ == '__main__':
	main()
