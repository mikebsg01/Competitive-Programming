def readInt():
	return int(raw_input())

def main():
	a = readInt()
	b = readInt()
	x = a - b if a > b else b - a

	ans = "ATRASAR" if a > b else "ADELANTAR"
	ans += " " + str(x) + " "
	ans += "SEGUNDOS" if x > 1 else "SEGUNDO"
	print(ans)

if __name__ == '__main__':
	main()
