#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
#define MAXN 52
#define INF1 INT_MAX
#define INF2 -1
#define ALL(x) x.begin(), x.end()
#define INS(s, x) s.insert(x)
#define PB(s, x) s.push_back(x)
#define MP make_pair
#define X first
#define Y second
using namespace std;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;

int M, N;
int T[MAXN][MAXN], RMQ[MAXN][MAXN];
int memo[MAXN][MAXN];
int ans;

int dp(int m, int n) {

	if (memo[m][n] != INF2) {
		return memo[m][n];
	}

	int val = RMQ[m][n];
	int blocks = m * n * val;

	if (m == 1 and n == 1) {
		return blocks;
	}

	if (m > 1 and n > 1) {
		int a = dp(m - 1, n);
		int b = dp(m, n - 1);

		int c = blocks - ((m - 1) * n * val) + a;
		int d = blocks - (m * (n - 1) * val) + b;
		return memo[m][n] = max(c, d);
	} else if (m > 1) {
		int a = dp(m - 1, n);
		int c = blocks - ((m - 1) * n * val) + a;
		return memo[m][n] = c;
	} else {
		int b = dp(m, n - 1);
		int d = blocks - (m * (n - 1) * val) + b;
		return memo[m][n] = d;
	}
}

int main() {
	int i, j, k, l, minVal, blocks, n, m;

	cin >> M;
	cin.ignore();
	cin >> N;

	for (i = 0; i < M; ++i) {
		for (j = 0; j < N; ++j) {
			if (j > 0) {
				cin.ignore();
			}

			cin >> T[i][j];
		}
	}

	for (i = M; i >= 1; --i) {
		for (j = N; j >= 1; --j) {
			minVal = INF1;

			for (k = 0; k < i; ++k) {
				for (l = 0; l < j; ++l) {
					minVal = min(minVal, T[k][l]);
				}
			}

			RMQ[i][j] = minVal;
		}
	}

	memset(memo, INF2, sizeof(memo));

	cout << dp(M, N) << endl;
	return 0;
}
