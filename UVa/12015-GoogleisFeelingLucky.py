from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def main():
	T = readInt()

	for i in range(T):
		pages = [{'url': None, 'v': 0} for j in range(10)]

		for j in range(10):
			pages[j]['url'], pages[j]['v'] = readLine().split()
			pages[j]['v'] = int(pages[j]['v'])
		
		maxVal = max(pages, key=lambda x: x['v'])['v']
		pages = list(filter(lambda x: x['v'] == maxVal, pages))

		print('Case #%d:' %(i + 1))
		for p in pages:
			print(p['url'])

if __name__ == '__main__':
	main()
