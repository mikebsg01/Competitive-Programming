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

def calcMinRadius(N: int = 0, K: int = 0) -> float:
    global points, distances
    distances = [dist(*point) for point in points]
    distances.sort()
    return distances[K - 1]

def main():
    global points, distances
    N, K = readInts()

    for i in range(N):
        point = readFloats()
        points.append(point)

    ans = calcMinRadius(N, K)
    print('%1.8f' % ans)

if __name__ == '__main__':
	main()