def avoidObstacles(a):
	a, n = [0]+sorted(a), len(a)
	for i in range(n):
		if (a[i] + 1) < a[i + 1]:
			for j in range(a[i] + 1, a[i + 1]):
				if all(a[k + 1] % j != 0 for k in range(n)):
					return j
	return a[-1] + 1

def main():
	a = [5, 3, 6, 7, 9]
	ans = avoidObstacles(a)
	print(ans)

	a = [1, 2, 3, 4, 6, 7]
	ans = avoidObstacles(a)
	print(ans)

	a = [1000, 999]
	ans = avoidObstacles(a)
	print(ans)

	a = [1, 4, 10, 6, 2]
	ans = avoidObstacles(a)
	print(ans)

if __name__ == '__main__':
	main()
