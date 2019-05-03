#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ":" << x << endl;
#define FOR(t,i,a,b) for(t i = a; i != b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i != b; --i)
#define MAXN 8
#define INF -1
using namespace std;

int T, P[MAXN + 2], p, ans;
bool vis[MAXN][MAXN];

bool isPossible(int row, int column) {
	RFOR(int, x, column - 1, -1) {
		if (vis[row][x]) {
			return false;
		}
	}

	for (int y = row - 1, x = column - 1; y >= 0 and x >= 0; --y, --x) {
		if (vis[y][x]) {
			return false;
		}
	}

	for (int y = row + 1, x = column - 1; y < MAXN and x >= 0; ++y, --x) {
		if (vis[y][x]) {
			return false;
		}
	}

	return true;
}

void backtrack(int initRow, int initColumn, int column) {
	if (column == MAXN) {
		++ans;

		cout << setw(2) << ans << "      ";

		FOR(int, i, 0, p) {
			if (i > 0) {
				cout << ' ';
			}

			cout << (P[i] + 1);
		}

		cout << '\n';
		return;
	} else if (column == initColumn) {
		if (isPossible(initRow, initColumn)) {
			P[p++] = initRow;
			backtrack(initRow, initColumn, column + 1);
			P[--p] = INF;
		}
		return;
	}

	FOR(int, row, 0, MAXN) {
		if (isPossible(row, column)) {
			vis[row][column] = true;
			P[p++] = row;
			backtrack(initRow, initColumn, column + 1);
			P[--p] = INF;
			vis[row][column] = false;
		}
	}
}

int main() {
	optimize_io
	int x, y;
	cin >> T;

	FOR(int, t, 0, T) {
		cin >> y >> x;
		--y; --x;
		memset(vis, 0, sizeof(vis));
		vis[y][x] = true;
		ans = 0;

		if (t > 0) {
			cout << '\n';
		}

		cout << "SOLN       COLUMN\n"
			 << " #      1 2 3 4 5 6 7 8\n\n";

		backtrack(y, x, 0);
	}
	return 0;
}