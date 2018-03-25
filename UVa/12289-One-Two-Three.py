from sys import stdin

def readNum():
	return int(stdin.readline())

def readLine():
	return stdin.readline().split()[0]

def main():
	words = [('one', 1), ('two', 2), ('three', 3)]
	n = readNum()

	for i in range(n):
		word = readLine()
		ans = None
		
		for j in range(len(words)):
			diff = 0

			if len(word) == len(words[j][0]):

				for k, l in zip(word, words[j][0]):
					if k != l:
						diff += 1

				if diff <= 1:
					ans = words[j][1]

		print(ans)

if __name__ == '__main__':
	main()
