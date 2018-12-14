#include <bits/stdc++.h>
#define PB push_back
#define ALL(x) x.begin(), x.end()
#define SZ size()
#define IS_ORDERED -1
using namespace std;

int isOrdered(vector<int> &v) {
	int i;

	for (i = 0; i < v.SZ - 1; ++i) {
		if (v[i] > v[i + 1]) {
			return i;
			break;
		}
	}
	return IS_ORDERED;
}

int main() {
	int T, N, i, j, x;
	vector<int> A[2], B;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		cin >> N;

		for (j = 0; j < N; ++j) {
			cin >> x;
			A[j % 2].PB(x);
		}

		sort(ALL(A[0]));
		sort(ALL(A[1]));

		for (j = 0; j < A[0].SZ or j < A[1].SZ; ++j) {
			if (j < A[0].SZ) {
				B.PB(A[0][j]);
			}

			if (j < A[1].SZ) {
				B.PB(A[1][j]);
			}
		}

		x = isOrdered(B);

		if (x != IS_ORDERED) {
			cout << "Case #" << i << ": " << x << "\n";
		} else {
			cout << "Case #" << i << ": OK\n";
		}
		
		A[0].clear(); 
		A[1].clear();
		B.clear();
	}
	return 0;
}
