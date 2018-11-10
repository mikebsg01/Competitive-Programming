#include <bits/stdc++.h>
#define dd(x) cout << x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define MAXN 1005
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;

int N, S;
bool T[2][MAXN];
vectori E[2][MAXN];
bool vis[MAXN], ans = false;

void dfs(int start, int end) {
	int i, n, j;

	if (start == end) {
		ans = true;
		return;
	}

	for (i = 0; i < 2; ++i) {
		for (j = 0, n = E[i][start].size(); j < n; ++j) {
			if (!vis[E[i][start][j]]) {
				vis[E[i][start][j]] = true;
				dfs(E[i][start][j], end);
			}
		}
	}
}

int main() {
	int i, j, k, x;
	cin >> N >> S;
	
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < N; ++j) {
			cin >> x;
			T[i][j] = (bool) x;
		}
	}

	for (i = 0, j = 0; j < N; ++j) {
		if (T[i][j]) {
			for (k = j + 1; k < N; ++k) {
				if (T[i][k]) {
					PB(E[i][j], k);
				}	
			}
		}
	}

	for (i = 1, j = N - 1; j >= 0; --j) {
		if (T[i][j]) {
			for (k = j - 1; k >= 0; --k) {
				if (T[i][k]) {
					PB(E[i][j], k);
				}
			}
		}
	}

	dfs(0, S - 1);
	cout << (ans ? "YES\n" : "NO\n");
	return 0;
}
