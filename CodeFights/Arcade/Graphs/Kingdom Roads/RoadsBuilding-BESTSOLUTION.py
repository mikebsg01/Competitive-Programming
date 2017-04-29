def roadsBuilding(cities, roads):
    roads = set([tuple(road) for road in roads])
    toBuild = []
    for i in range(0,cities-1):
        for j in range(i+1,cities):
            if (i,j) not in roads and (j,i) not in roads:
                toBuild.append([i,j])
    return toBuild

def main():
    cities = 4
    roads = [[0, 1], [1, 2], [2, 0]]
    print(roadsBuilding(cities, roads))

if __name__ == "__main__" : main()
