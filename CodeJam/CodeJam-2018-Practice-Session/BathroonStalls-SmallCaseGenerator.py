def main():
	n = 100
	print(int((n * (n + 1)) / 2))
	for i in range(1, n + 1):
		for j in range(1, i + 1):
			print(i, j)

if __name__ == '__main__':
	main()
