#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define MAXM 22
using namespace std;

int N, M, A[MAXM], P[MAXM], p, Q[MAXM], q, ans;

void backtrack(int idx, int sum) {
	if (sum > N) {
		return;
	} else if (idx == M) {
		if (sum > ans) {
			ans = sum, q = 0;

			FOR(i, 0, p) {
				Q[q++] = P[i];
			}
		}
		return;
	}

	P[p++] = A[idx];
	backtrack(idx + 1, sum + A[idx]);
	P[--p] = 0;
	backtrack(idx + 1, sum);
}

int main() {
	optimize_io
	while (cin >> N) {
		cin >> M;

		FOR(i, 0, M) {
			cin >> A[i];
		}

		ans = 0;
		backtrack(0, 0);

		FOR(i, 0, q) {
			cout << Q[i] << ' ';
		}

		cout << "sum:" << ans << '\n';
	}
	return 0;
}
