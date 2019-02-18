#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define MAXN ((int)(1e6+2))
using namespace std;
typedef long long int lli;

int N, Q;
lli BIT[MAXN];

void update(int idx, lli val) {
	while (idx <= N) {
		BIT[idx] += val;
		idx += idx & (-idx);
	}
}

lli query(int idx) {
	lli sum = 0;
	while (idx > 0) {
		sum += BIT[idx];
		idx -= idx & (-idx);
	}
	return sum;
}

int main() {
	optimize_io
	int a, b;
	char c;
	cin >> N;
	FOR(i, 1, N + 1) {
		cin >> a;
		update(i, a);
	}
	cin >> Q;
	FOR(i, 0, Q) {
		cin >> c >> a >> b;
		if (c == 'q') {
			cout << query(b) - query(a-1) << '\n';
		} else {
			update(a, b);
		}
	}
	return 0;
}

