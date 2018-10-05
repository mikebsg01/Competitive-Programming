#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 27
#define N_MOVES 8
using namespace std;

short N;
bool T[MAXN][MAXN];
bool vis[MAXN][MAXN];
const short MOV_Y[N_MOVES] = {-1, -1, 0, 1, 1, 1, 0, -1};
const short MOV_X[N_MOVES] = {0, 1, 1, 1, 0, -1, -1, -1};

inline bool isInside(short y, short x) {
	return y >= 0 and y < N and x >= 0 and x < N;
}

short dfs(short y, short x) {
	if (vis[y][x]) {
		return 0;
	}

	short i, yt, xt, counter = 1;

	vis[y][x] = true;
	
	for (i = 0; i < N_MOVES; ++i) {
		yt = y + MOV_Y[i];
		xt = x + MOV_X[i];

		if (isInside(yt, xt) and T[yt][xt]) {
			counter += dfs(yt, xt);
		}
	}

	return counter;
}

int main() {
	optimize_ios

	int imgNum = 1;
	short i, j, counter, ans;
	char c;

	while (cin >> N) {
		ans = 0;
		
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				cin >> c;
				T[i][j] = (bool) (c == '1');
			}
		}

		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (T[i][j] and !vis[i][j]) {
					counter = dfs(i, j);
					++ans;
				}
			}
		}

		cout << "Image number " << imgNum << " contains " << ans << " war eagles.\n";
		++imgNum;
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}
