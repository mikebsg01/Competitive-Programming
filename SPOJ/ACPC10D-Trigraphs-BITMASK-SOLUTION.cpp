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
lli DP[2][MAXM];

inline lli dp(int y, int x) {
	return (x < 0 or x >= MAXM) ? INF : DP[y][x];
}

int main() {
	int k, i, bit, j, l;
	lli a, b, c, d, t;

	for (k = 1; cin >> N; ++k) {

		if (N == 0) {
			break;
		}
		
		for (i = 0; i < N; ++i) {
			bit = i & 1;

			cin >> DP[bit][0] >> DP[bit][1] >> DP[bit][2];

			if (i == 0) {
				DP[0][0] = INF;
				DP[0][2] += DP[0][1];
				continue;
			}

			for (j = 0; j < MAXM; ++j) {
				a = dp(bit, j - 1);
				b = dp(bit ^ 1, j - 1);
				c = dp(bit ^ 1, j);
				d = dp(bit ^ 1, j + 1);

				DP[bit][j] += min(min(a, b), min(c, d));
			}
		}
		cout << k << ". " <<  DP[bit][1] << "\n";
	}
	return 0;
}
