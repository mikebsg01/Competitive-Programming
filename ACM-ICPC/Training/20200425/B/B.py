from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def f(n):
    x = i = 1
    y = diff = best_diff = ans = 0

    while x <= n:
        x *= 10

    x //= 10

    while True:
        y = x * i
        diff = abs(n - y)

        if i == 1:
            best_diff = diff
            ans = y
        elif diff <= best_diff:
            best_diff = diff
            ans = y

        if y > n:
            break  

        i += 1

    return ans


def main():
	N = readInt()
	print(f(N))

if __name__ == '__main__':
	main()