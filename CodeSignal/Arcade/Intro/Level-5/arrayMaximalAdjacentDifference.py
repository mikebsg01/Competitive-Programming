def arrayMaximalAdjacentDifference(a):
	return max([abs(a[i] - a[i + 1]) for i in range(len(a)-1)])

def main():
	a = [2, 4, 1, 0]
	ans = arrayMaximalAdjacentDifference(a)
	print(ans)

if __name__ == '__main__':
	main()
