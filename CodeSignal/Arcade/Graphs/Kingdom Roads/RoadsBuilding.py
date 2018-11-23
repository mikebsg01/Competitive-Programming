def roadsBuilding(c, r):
    m = [[False for i in range(c)] for j in range(c)]
    ans = []
    for i in range(len(r)):
        m[r[i][0]][r[i][1]] = m[r[i][1]][r[i][0]] = True
    for i in range(c):
        for j in range(c):
            if i != j and not m[i][j]:
                m[i][j] = m[j][i] = True
                ans.append([i, j])
    return ans

def main():
    cities = 4
    roads = [[0, 1], [1, 2], [2, 0]]
    print(roadsBuilding(cities, roads))

if __name__ == "__main__": main()
