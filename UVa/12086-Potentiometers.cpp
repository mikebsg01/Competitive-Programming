#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define PB(s,x) s.push_back(x)
#define SZ .size()
#define MAXN 200005
using namespace std;
typedef vector<int> vectori;

int N, A[MAXN], BIT[MAXN];

void update(int idx, int add) {
	while (idx <= N) {
		BIT[idx] += add;
		idx += (idx & (-idx));
	}
}

int query(int idx) {
	int sum = 0;

	while (idx > 0) {
		sum += BIT[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}

int main() {
	optimize_io
	string op;
	int x, a, b, t = 1;

	while (cin >> N, N != 0) {
		if (t > 1) {
			cout << '\n';
		}

		cout << "Case " << t << ":\n";

		FOR(i, 1, N + 1) {
			cin >> A[i];
			update(i, A[i]);
		}

		while (cin >> op, op != "END") {
			cin >> a >> b;

			if (op == "M") {
				cout << query(b) - query(a - 1) << '\n';
			} else {
				update(a, b - A[a]);
				A[a] = b;
			}
		}

		memset(BIT, 0, sizeof(BIT));
		++t;
	}
	return 0;
}
