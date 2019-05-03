from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

achieve = [56, 51, 41, 36]

def isOudler(s):
	return s.startswith('one') or s.startswith('twenty-one') or s.startswith('fool')

def isKing(s):
	return s.startswith('king')

def isQueen(s):
	return s.startswith('queen')

def isKnight(s):
	return s.startswith('knight')

def isJack(s):
	return s.startswith('jack')

def main():
	global achieve
	T = readInt()

	for t in  range(T):
		N = readInt()
		oudlers = 0
		points = 0

		for i in range(N):
			S = readLine()

			if isOudler(S):
				oudlers += 1
				points += 4.5
			elif isKing(S):
				points += 4.5
			elif isQueen(S):
				points += 3.5
			elif isKnight(S):
				points += 2.5
			elif isJack(S):
				points += 1.5
			else:
				points += .5
			
		ans = achieve[oudlers] - points

		if t > 0:
			print()
		
		print('Hand #%d\nGame %s by %d point(s).' %(t + 1, 'lost' if ans > 0 else 'won', abs(ans)))

if __name__ == '__main__':
	main()