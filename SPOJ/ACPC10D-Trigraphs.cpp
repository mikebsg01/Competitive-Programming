#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 3
#define INF INT_MAX-2
#define dd(x) cout << #x << ": " << x << endl
#define ddc(a,b,c,d) cout << #a << ": " << a << " " \
			<< #b << ": " << b << " " \
			<< #c << ": " << c << " " \
			<< #d << ": " << d << endl;
using namespace std;
typedef int lli;

int N;
lli DP[MAXN][MAXM];

inline lli dp(int y, int x) {
	if (y < 0 or x < 0 or x >= 3) {
		return INF;
	}
	
	return DP[y][x];
}

int main() {
	int k, i, j, l;
	lli a, b, c, d, t;

	for (k = 1; cin >> N; ++k) {

		if (N == 0) {
			break;
		}
		
		for (i = 0; i < N; ++i) {
			cin >> DP[i][0] >> DP[i][1] >> DP[i][2];

			if (i > 0) {
				l = 0;
			} else {
				DP[0][0] = INF;
				l = MAXM - 1;
			}

			for (j = l; j < MAXM; ++j) {
				a = dp(i, j - 1);
				b = dp(i - 1, j - 1);
				c = dp(i - 1, j);
				d = dp(i - 1, j + 1);

				DP[i][j] += min(min(a, b), min(c, d));
			}
		}
		cout << k << ". " <<  DP[N - 1][1] << "\n";
	}
	return 0;
}
