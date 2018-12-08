#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout<<#x<<": "<<x<<endl;
#define FACES 6
#define MAXN 545
#define MAXK 2726
using namespace std;

int T, N, K;
double DP[MAXN][MAXK];

inline double prob(double x) {
	return x / ((double) FACES);
}

inline double dp(int i, int j) {
	return ((j >= 0) ? DP[i][j] : 0);
}

void precalculate() {
	int i, j, m = FACES;

	for (j = 0; j < m; ++j) {
		DP[0][j] = prob(1.0);
	}

	for (i = 1; i < MAXN; ++i) {
		m += FACES - 1;

		for (j = 0; j < m; ++j) {
			DP[i][j] = dp(i, j - 1) + prob(dp(i - 1, j) - dp(i - 1, j - FACES));
		}
	}
}

inline int percent(double n) {
	return ((int) (n * 100));
}

int main() {
	optimize_io
	int L, R, i;
	cin >> T;
	precalculate();

	while (T--) {
		cin >> N >> K;
		L = N;
		R = FACES * N;

		if (N > MAXN or K < L or K >= MAXK) {
			cout << "0\n";
		} else {
			cout << percent(DP[N - 1][K - L]) << '\n';
		}
	}
	return 0;
}
