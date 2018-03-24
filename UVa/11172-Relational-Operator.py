def main():
	t = int(input())

	for i in range(0, t):
		a, b = map(int, input().split())
		print('>' if a > b else '<' if a < b else '=')

if __name__ == '__main__':
	main()
