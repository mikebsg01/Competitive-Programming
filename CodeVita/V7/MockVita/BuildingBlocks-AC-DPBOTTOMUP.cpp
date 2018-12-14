#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
#define MAXN 52
#define INF INT_MAX
using namespace std;

int M, N;
int T[MAXN][MAXN], RMQ[MAXN][MAXN], DP[MAXN][MAXN];

int dp() {
	int i, j, val, blocks, up, left;

	for (i = 1; i <= M; ++i) {
		for (j = 1; j <= N; ++j) {
			val = RMQ[i][j];
			blocks = (i * j * val);

			up = blocks - ((i - 1) * j * val) + DP[i - 1][j];
			left = blocks - (i * (j - 1) * val) + DP[i][j - 1];

			DP[i][j] = max(up, left);
		}
	}

	return DP[M][N];
}

int main() {
	int i, j, k, l, minVal;
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

	for (i = 1; i <= M; ++i) {
		for (j = 1; j <= N; ++j) {
			minVal = INF;

			for (k = 0; k < i; ++k) {
				for (l = 0; l < j; ++l) {
					minVal = min(minVal, T[k][l]);
				}
			}

			RMQ[i][j] = minVal;
		}
	}
	
	cout << dp() << '\n';
	return 0;
}
