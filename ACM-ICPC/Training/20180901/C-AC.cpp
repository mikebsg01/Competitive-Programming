#include <bits/stdc++.h>
#define MAXN 10001
#define MOD 1000000007
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef unsigned long long int ulli;

int N;
ulli DP[MAXN][MAXN];

inline ulli dp(int y, int x) {
	if (y < 0) {
		return 0;
	} else if (x > y) {
		return DP[y][y];
	}

	return DP[y][x];
}

void precalculate() {
	int i, j;

	for (i = 1; i < MAXN; ++i) {
		DP[i][1] = DP[1][i] = DP[i][i] = 1;
	}

	for (i = 2; i < MAXN; ++i) {
		for (j = 2; j <= i; ++j) {
			DP[i][j] += (dp(i - j, j) + dp(i, j - 1)) % MOD;
			DP[i][j] %= MOD;
		}
	}
}

int main() {
	optimize_ios

	precalculate();

	while (cin >> N) {
		cout << DP[N][N] << "\n";
	}
	return 0;
}
