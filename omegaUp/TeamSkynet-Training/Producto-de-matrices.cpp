#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 102
using namespace std;

int N, M, O;
int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];

void multiplyMatrix() {
	int i, j, k;

	for (i = 0; i < N; ++i) { /* A rows */
		for (j = 0; j < O; ++j) { /* B columns */
			for (k = 0; k < M; ++k) { /* A Columns */
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

int main() {
	optimize_ios

	int i, j;

	cin >> N >> M >> O;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}

	for (i = 0; i < M; ++i) {
		for (j = 0; j < O; ++j) {
			cin >> B[i][j];
		}
	}

	multiplyMatrix();

	for (i = 0; i < N; ++i) {
		for (j = 0; j < O; ++j) {
			if (j > 0) {
				cout << ' ';
			}

			cout << C[i][j];
		}
		cout << '\n';
	}
	return 0;
}
