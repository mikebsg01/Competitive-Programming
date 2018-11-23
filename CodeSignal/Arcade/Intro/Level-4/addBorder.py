def addBorder(l):
	n = len(max(l, key=len))
	r = ['*' * (n + 2)] + list(map(lambda x: '%s%s%s' %('*', x, '*'), l)) + ['*' * (n + 2)]
	return r

def main():
	picture = ["abc", "ded"]
	ans = addBorder(picture)
	for x in ans:
		print(x)

if __name__ == '__main__':
	main()
