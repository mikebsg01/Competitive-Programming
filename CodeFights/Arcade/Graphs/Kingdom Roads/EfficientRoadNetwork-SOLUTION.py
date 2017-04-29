from collections import deque

INF = 3

def bfs(n, al, a):
    v = [False for i in range(n)]
    v[a] = True
    q = deque([[a, 0]])
    d = 0

    while len(q):
        c = q.popleft()
        d = max(d, c[1]) 
        for i in range(len(al[c[0]])):
            if not v[al[c[0]][i]]:
                v[al[c[0]][i]] = True
                q.append([al[c[0]][i], c[1] + 1])
    for i in range(n):
        if not v[i]:
            return INF
    return d

def efficientRoadNetwork(n, r):
    al = [[] for i in range(n)]
    for i in range(len(r)):
        al[r[i][0]].append(r[i][1])
        al[r[i][1]].append(r[i][0])
    for i in range(n):
        ans = bfs(n,al,i)
        if ans > 2:
            return False
    return True

def main():
    n = 6
    roads = [[0, 4], [5, 0], [2, 1], [1, 4], [2, 3], [5, 2]]
    print(efficientRoadNetwork(n, roads))

if __name__ == "__main__" : main()
