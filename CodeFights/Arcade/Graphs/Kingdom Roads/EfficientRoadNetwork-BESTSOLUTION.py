INF = 35001

def efficientRoadNetwork(n, roads):
    vertex_dict = dict()
    for i in range(0,n):
        vertex_dict[i] = set()
    for road in roads:
        i,j = road
        if j not in vertex_dict[i]:
            vertex_dict[i].add(j)
        if i not in vertex_dict[j]:
            vertex_dict[j].add(i)
    for i in range(0,n):
        for j in range(i+1,n):
            if i in vertex_dict[j] or j in vertex_dict[i] or len(vertex_dict[i]&vertex_dict[j]) >= 1:
                continue
            else:
                return False
    return True

def main():
    n = 6
    roads = roads = [[0, 4], [5, 0], [2, 1],[1, 4], [2, 3], [5, 2]]
    print(efficientRoadNetwork(n, roads))

if __name__ == "__main__" : main()
