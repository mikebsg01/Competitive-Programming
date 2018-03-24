def main():
	t = int(input())
	
	for i in range(0, t):
		n = int(input())
		storePos = list(map(int, input().split()))
		storePos.sort()
		storePos.append(storePos[0])
		ans = 0
		
		for j in range(0, len(storePos) - 1):
			ans += abs(storePos[j] - storePos[j + 1])

		print(ans)

if __name__ == '__main__':
	main()
