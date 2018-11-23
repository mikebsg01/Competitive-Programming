def palindromeRearranging(s):
	s = sorted(s)
	print(s)
	n = len(s)
	p, r, = n // 2, n % 2
	i = pp = rr = 0
	while i < n:
		if (i + 1) < n and s[i] == s[i + 1]:
			pp += 1
			i += 1
		else:
			rr += 1
		i += 1	
	return p == pp and r == rr
	

def main():
	# Test Case No. 1
	s = 'aabb'
	ans = palindromeRearranging(s)
	print(ans)

	# Test Case No. 2
	s = 'abbcabb'
	ans = palindromeRearranging(s)
	print(ans)

if __name__ == '__main__':
	main()
