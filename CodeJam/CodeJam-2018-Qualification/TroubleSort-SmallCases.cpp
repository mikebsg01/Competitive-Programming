#include <bits/stdc++.h>
#define PB push_back
#define INF -1
using namespace std;

int N;
vector<int> A;

void troubleSort() {
	int i;
	bool done = false;

	while (! done) {
		done = true;

		for (i = 0; i < N - 2; ++i) {
			if (A[i] > A[i + 2]) {
				done = false;
				swap(A[i], A[i + 2]);
			}
		}
	}
}

int isOrdered() {
	int i;

	for (i = 0; i < N - 1; ++i) {
		if (A[i] > A[i + 1]) {
			return i;
		}
	}
	return INF;
}

int main() {
	int T, i, j, x, idx;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		cin >> N;
		A.clear();

		for (j = 0; j < N; ++j) {
			cin >> x;
			A.PB(x);
		}

		troubleSort();
		idx = isOrdered();

		cout << "Case #" << i << ": ";

		if (idx != INF) {
			cout << idx;
		} else {
			cout << "OK";
		}

		cout << "\n";
	}
	return 0;
}
