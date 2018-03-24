def main():
	t = int(input())
	
	for i in range(0, t):
		n = int((((((int(input()) * 567) / 9) + 7492) * 235) / 47) - 498) 
		print(str(n)[-2])

if __name__ == '__main__':
	main()
