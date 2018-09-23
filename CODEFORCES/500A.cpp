#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M;

int main() {
	optimize_ios

	int i, n, a, pos = 1;
	bool solved = false;

	cin >> N >> M;
	n = N - 1;

	for (i = 1; i <= n; ++i) {
		cin >> a;

		if (!solved) {
			if (pos == M) {
				cout << "YES\n";
				solved = true;
			} else if (pos == i) {
				pos += a;

				if (pos > M) {
					cout << "NO\n";
					solved = true;
				}
			}
		}
	}

	if (!solved) {
		cout << ((pos == N) ? "YES\n" :  "NO\n");
	}
	return 0;
}
