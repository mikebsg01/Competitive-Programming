from sys import stdin
from math import sqrt

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def readFloats():
	return list(map(float, readLine().split()))

points = []
distances = []

def dist(x: float = float(0), y: float = float(0), z: float = float(0)) -> float:
    return float(sqrt((x * x) + (y * y) + (z * z)))

def f(radius: float = float(0)) -> int:
    global points, distances
    ans = 0

    for point in points:
        d = dist(*point)

        if d <= radius:
            ans += 1

    return ans


def binary(a: int = 0, b: int = 0, x: int = 0) -> int:
    global points, distances
    while a < b:
        m = (a + b) // 2
        radius = distances[m]

        if f(radius) < x:
            a = m + 1
        else:
            b = m

    return a


def calcMinRadius(N: int = 0, K: int = 0) -> float:
    global points, distances
    distances = [dist(*point) for point in points]
    distances.sort()
    pos = binary(0, N, K)
    return distances[pos]

def main():
    global points, distances
    N, K = readInts()

    for i in range(N):
        point = readFloats()
        points.append(point)

    ans = calcMinRadius(N, K)
    print('%1.8f' % ans)

    for distance in distances:
        print(distance)

if __name__ == '__main__':
	main()