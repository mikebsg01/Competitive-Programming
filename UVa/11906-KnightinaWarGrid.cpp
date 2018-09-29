#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 102
#define MP make_pair
#define X first
#define Y second
#define INF -1
using namespace std;
typedef pair<int, int> P;
typedef set<P> S;

int T, R, C, M, N, W;
int MOV_Y[8], MOV_X[8];
int reachables[MAXN][MAXN];
bool isWater[MAXN][MAXN], vis[MAXN][MAXN];

inline bool isInside(int y, int x) {
	return y >= 0 and x >= 0 and y < R and x < C;
}

void dfs(int y, int x) {
	if (vis[y][x]) {
		return;
	}	

	vis[y][x] = true;

	int i, yt, xt;
	S grids;
	P t;

	for (i = 0; i < 8; ++i) {
		yt = y + MOV_Y[i];
		xt = x + MOV_X[i];

		if (isInside(yt, xt) and !isWater[yt][xt]) {
			grids.insert(MP(yt, xt));
		}
	}

	reachables[y][x] = grids.size();

	for (S::iterator it = grids.begin(); it != grids.end(); ++it) {
		t = (*it);
		dfs(t.X, t.Y);
	}
}

int main() {
	optimize_ios

	int i, j, k, l, p, y, x, val, even, odd;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		memset(isWater, 0, sizeof(isWater));
		memset(vis, 0, sizeof(vis));
		memset(reachables, INF, sizeof(reachables));
		
		p = even = odd = 0;

		cin >> R >> C >> M >> N >> W;

		for (j = 0; j < W; ++j) {
			cin >> y >> x;
			isWater[y][x] = 1;
		}

		for (j = 0; j < 2; ++j) {
			for (k = 1; k >= -1; k -= 2) {
				for (l = 1; l >= -1; l -= 2) {
					MOV_Y[p] = k * M;
					MOV_X[p] = l * N;
					++p;
				}
			}
			swap(M, N);
		}

		dfs(0, 0);

		for (j = 0; j < R; ++j) {
			for (k = 0; k < C; ++k) {
				val = reachables[j][k];

				if (val != INF) {
					if (val & 1) {
						++odd;
					} else {
						++even;
					}
				}
			}
		}

		cout << "Case " << i << ": " << even << ' ' << odd << "\n";		
	}
	return 0;
}
