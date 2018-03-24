from sys import stdin

def main():
	while True:
		k = int(stdin.readline())

		if not k:
			break

		x, y = map(int, stdin.readline().split())
		
		for i in range(0, k):
			xt, yt = map(int, stdin.readline().split())
			
			if xt == x or yt == y:
				print("divisa")
			else:
				print(('N' if yt > y else 'S') + ('E' if xt > x else 'O'))	


if __name__ == '__main__':
	main()
