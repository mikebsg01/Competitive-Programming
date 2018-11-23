def arrayChange(a):
	r = 0
	for i in range(1, len(a)):
		if a[i - 1] >= a[i]:
			t = a[i - 1] - a[i] + 1
			a[i] += t
			r += t
	return r

def main():
	a = [1, 1, 1]
	ans = arrayChange(a)
	print(ans)

if __name__ == '__main__':
	main()
