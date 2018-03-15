t = int(input())

for i in range(t):
	n, m = map(int, input().split(' '))
	print(int(n / 3) * int(m / 3))
