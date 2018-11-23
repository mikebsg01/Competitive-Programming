INF = 35001

def efficientRoadNetwork(n, r):
    m = [[INF if i != j else 0 for i in range(n)] for j in range(n)]
    
    for i in range(len(r)):
        m[r[i][0]][r[i][1]] = 1
        m[r[i][1]][r[i][0]] = 1

    for k in range(0,n):
        for i in range(0,n):
            for j in range(0,n):
                m[i][j] = min([m[i][j], m[i][k] + m[k][j]])
    
    for i in range(0,n):
        for j in range(i+1,n):
            if m[i][j] > 2:
                return False
    return True

def main():
    n = 6
    roads = roads = [[0, 4], [5, 0], [2, 1],[1, 4], [2, 3], [5, 2]]
    print(efficientRoadNetwork(n, roads))

if __name__ == "__main__" : main()
