def areSimilar(a, b):
	e, f, d = sorted(a), sorted(b), 0
	if e != f:
		return False
	for i in range(len(a)):
		if a[i] != b[i]:
			d += 1
	return True if d == 0 or d == 2 else False

def main():
	# Test Case No. 1
	a = [1, 2, 3]
	b = [1, 2, 3]
	ans = areSimilar(a, b)
	print(ans)

	# Test Case No. 2
	a = [1, 2, 3]
	b = [2, 1, 3]
	ans = areSimilar(a, b)
	print(ans)

	# Test Case No. 3
	a = [1, 2, 2]
	b = [2, 1, 1]
	ans = areSimilar(a, b)
	print(ans)

	# Test Case No. 4
	a = [1, 1, 4]
	b = [1, 2, 3]
	ans = areSimilar(a, b)
	print(ans)

if __name__ == '__main__':
	main()
