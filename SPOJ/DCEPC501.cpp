#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define MAXN ((int)(1e5+30))
#define MAXX 3
#define UNVISITED -1
using namespace std;
typedef long long int lli;

int T, N;
int A[MAXN];
lli DP[MAXN];

lli dp(int idx) {
	if (idx >= N) {
		return 0;
	}

	if (DP[idx] != UNVISITED) {
		return DP[idx];
	}

	lli current, sum = 0, greatest = 0;

	for (int i = 1; i <= MAXX; ++i) {
		sum += A[idx + i - 1];
		current = sum + dp(idx + (2 * i));
		greatest = max(greatest, current);
	}

	return DP[idx] = greatest; 
}

int main() {
	optimize_io
	int i, j;
	cin >> T;

	while (T--) {
		cin >> N;
		memset(DP, UNVISITED, sizeof(DP));
		memset(A, 0, sizeof(A));

		for (i = 0; i < N; ++i) {
			cin >> A[i];
		}

		cout << dp(0) << '\n';
	}
	return 0;
}
