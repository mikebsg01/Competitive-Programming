#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,b,a) for (int i = b; i > a; --i)
#define MAXN 8
#define QUEENS 8
using namespace std;

int K, T[MAXN + 2][MAXN + 2], ans;
bool vis[MAXN + 2][MAXN + 2];

bool isPossible(int y, int x) {
	RFOR(i, x - 1, -1) {
		if (vis[y][i]) {
			return false;
		}
	}

	for (int i = y - 1, j = x - 1; i >= 0 and j >= 0; --i, --j) {
		if (vis[i][j]) {
			return false;
		}
	}

	for (int i = y + 1, j = x - 1; i < MAXN and j >= 0; ++i, --j) {
		if (vis[i][j]) {
			return false;
		}
	}

	return true;
}

void backtrack(int column, int score) {
	if (column == QUEENS) {
		if (score > ans) {
			ans = score;
		}
		return;
	}

	FOR(i, 0, MAXN) {
		if (!vis[i][column] and isPossible(i, column)) {
			vis[i][column] = true;
			backtrack(column + 1, score + T[i][column]);
			vis[i][column] = false;
		}
	}
}

int main() {
	optimize_io
	cin >> K;

	FOR(k, 0, K) {
		FOR(i, 0, MAXN) {
			FOR(j, 0, MAXN) {
				cin >> T[i][j];
			}
		}

		ans = 0;
		backtrack(0, 0);
		cout << setw(5) << right << ans << '\n';
	}
	return 0;
}
