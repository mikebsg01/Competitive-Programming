from sys import stdin

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

DAYS = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def f(m, d):
    return ((6 - m) * (6 - m)) + abs(d - 15)

def main():
    global DAYS
    N = readInt()
    R1, R2 = readInts()
    Target = readInt()

    for TV in range(0, N + 1):
        withoutTV = N - TV
        t = 0
        s = 0

        for month in range(1, 13):
            days = DAYS[month - 1]

            for day in range(1, days + 1):
                patients = f(month, day)
                clients = min(patients, N)
                a = min(clients, withoutTV)
                b = clients - a
                t += (a * R2) + (b * R1)

        if t >= Target:
            print(TV)
            return
    
    print(N)
    return

if __name__ == '__main__':
	main()
