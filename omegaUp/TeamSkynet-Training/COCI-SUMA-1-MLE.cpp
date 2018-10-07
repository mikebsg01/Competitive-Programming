#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 702
#define M 0
#define B 1
#define N_MOVS 4
#define NEVER -2
#define INF -1
#define LEFT 0
#define UP 1
#define Y first
#define X second
using namespace std;
typedef pair<int, int> P;

int N;
double T[MAXN][MAXN][2];
set<double> vis[MAXN][MAXN];
int nodesVisited[MAXN][MAXN][N_MOVS];
short MOV_Y[N_MOVS] = {0, 1,  0, -1};
short MOV_X[N_MOVS] = {1, 0, -1,  0};
queue<P> Q;
int ans = 1;

inline double intersect(int y, int x, int yt, int xt) {
	double	m1 = T[y][x][M],
		b1 = T[y][x][B],
		m2 = T[yt][xt][M],
		b2 = T[yt][xt][B];

	double	a = b1 - b2, 
		b = m2 - m1;
	
	if (b == 0) {

		if (b == a) {
			return INF;
		}

		return NEVER;

	}

	double res = a / b;

	if (res < 0) {
		return NEVER;
	}

	return res;
}

inline bool isInside(int y, int x) {
	return y >= 0 and y < N and x >= 0 and x < N;
}

inline bool isInSet(int y, int x, double element) {
	return vis[y][x].find(element) != vis[y][x].end();
}

int bfs(int y, int x, double srcIntersectionY) {
	if (isInSet(y, x, srcIntersectionY)) {
		return 1;
	}

	int i, yt, xt, nodesVisited = 0;
	double intersectionX, intersectionY;
	
	P current;
	Q.emplace(y, x);
	vis[y][x].insert(srcIntersectionY);

	while (!Q.empty()) {
		current = Q.front();
		Q.pop();
		++nodesVisited;

		for (i = 0; i < N_MOVS; ++i) {
			yt = current.Y + MOV_Y[i];
			xt = current.X + MOV_X[i];
			intersectionX = intersectionY = NEVER;

			if (isInside(yt, xt)) {
				intersectionX = intersect(y, x, yt, xt);
			}

			if (intersectionX != NEVER) {
				intersectionY = (T[y][x][M] * intersectionX) + T[y][x][B];

				if ((intersectionY == srcIntersectionY or intersectionX == INF) and !isInSet(yt, xt, srcIntersectionY)) {
					vis[yt][xt].insert(srcIntersectionY);
					Q.emplace(yt, xt);
				}
			}
		}
	}
	return nodesVisited;
}

void floodFill() {
	int y, x, yt, xt, i, res;
	double intersectionX, intersectionY;

	for (y = 0; y < N; ++y) {
		for (x = 0; x < N; ++x) {
			for (i = 0; i < N_MOVS; ++i) {
				yt = y + MOV_Y[i];
				xt = x + MOV_X[i];
				intersectionX = intersectionY = NEVER;

				if (isInside(yt, xt)) {
					intersectionX = intersect(y, x, yt, xt);
				}

				if (intersectionX != NEVER) {
					intersectionY = (T[y][x][M] * intersectionX) + T[y][x][B];
					res = bfs(yt, xt, intersectionY);
					nodesVisited[y][x][i] = res; 
				}	
			}
		}
	}
}

int main() {
	optimize_ios

	int i, j, k, it, jt;
	double x;

	cin >> N;

	for (i = 1; i >= 0; --i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				cin >> x;
				T[j][k][i] = x;
			}
		}
	}
	floodFill();

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N_MOVS; ++k) {
				ans = max(ans, nodesVisited[i][j][k]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
