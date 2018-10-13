#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define PB push_back
using namespace std;

int N;
vector<int> A;
queue<int> L;
stack<int> R;

void mergeSort(int a, int b) {
	if (a == b) {
		return;
	}

	int i, m = (a + b) / 2, l, r;

	mergeSort(a, m);
	mergeSort(m + 1, b);

	for (i = a; i <= m; ++i) {
		L.push(A[i]);
	}

	for (i = m + 1; i <= b; ++i) {
		R.push(A[i]);
	}

	i = a;

	while (!L.empty() or !R.empty()) {
		if (!L.empty() and !R.empty()) {
			l = L.front();
			r = R.top();

			if (l <= r) {
				A[i++] = l;
				L.pop();
			} else {
				A[i++] = r;
				R.pop();
			}
		} else if (!L.empty()) {
			A[i++] = L.front();
			L.pop();
		} else {
			A[i++] = R.top();
			R.pop();
		}
	}
}

int main() {
	optimize_ios

	int i, x;

	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> x;
		A.PB(x);
	}

	mergeSort(0, A.size() - 1);

	for (i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
