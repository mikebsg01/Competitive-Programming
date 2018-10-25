#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 200005
using namespace std;

int N, A[MAXN], IDX[MAXN];

int main() {
	optimize_ios

	int i, b, idx, limit;

	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> A[i];
		IDX[A[i]] = i;
	}

	limit = -1;

	for (i = 0; i < N; ++i) {
		cin >> b;
		
		idx = IDX[b];

		if (limit < idx) {
			cout << (idx - limit) << ' ';
			limit = idx;
		} else {
			cout << "0 ";
		}
	}

	cout << '\n';
	return 0;
}
