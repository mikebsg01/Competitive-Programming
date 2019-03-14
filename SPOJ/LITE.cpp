#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,b,a) for (int i = b; i > a; --i)
#define MP make_pair
#define X first
#define Y second
#define SZ size()
#define LC(x) (2 * x + 1)
#define RC(x) (2 * x + 2)
#define POSSIBLE_VALUES 2
using namespace std;
typedef pair<int, int> Pair;

int N, M;
vector<Pair> ST;
vector<int> lazy;

void init() {
	int	logn = ceil(log2(N)) + 1,
		n = (1 << logn) - 1;

	ST.assign(n, MP(0, 0));
	lazy.assign(n, 0);
}

void calc(int node) {
	ST[node].X = ST[LC(node)].X + ST[RC(node)].X;
	ST[node].Y = ST[LC(node)].Y + ST[RC(node)].Y;
}

void build(int node, int a, int b) {
	if (a == b) {
		ST[node].X = 1;
		return;
	}

	int m = (a + b) >> 1;
	build(LC(node), a, m);
	build(RC(node), m + 1, b);
	calc(node);
}

void turn(int node) {
	swap(ST[node].X, ST[node].Y);
}

void updateRange(int node, int a, int b, int l, int r) {
	int t = lazy[node] % POSSIBLE_VALUES;
	
	if (t > 0) {
		FOR(i, 0, t) {
			turn(node);
		}

		if (a != b) {
			lazy[LC(node)] += t;
			lazy[RC(node)] += t;
		}

		lazy[node] = 0;
	}

	if (b < l or r < a) {
		return;
	} else if (l <= a and b <= r) {
		turn(node);

		if (a != b) {
			lazy[LC(node)] += 1;
			lazy[RC(node)] += 1;
		}
		return;
	}

	int m = (a + b) >> 1;
	updateRange(LC(node), a, m, l, r);
	updateRange(RC(node), m + 1, b, l, r);
	calc(node);
}

int queryRange(int node, int a, int b, int l, int r) {
	if (b < l or r < a) {
		return 0;
	}

	int t = lazy[node] % POSSIBLE_VALUES;

	if (t > 0) {
		FOR(i, 0, t) {
			turn(node);
		}

		if (a != b) {
			lazy[LC(node)] += t;
			lazy[RC(node)] += t;
		}

		lazy[node] = 0;
	}

	if (l <= a and b <= r) {
		return ST[node].Y;
	}

	int m = (a + b) >> 1;
	return queryRange(LC(node), a, m, l, r) + queryRange(RC(node), m + 1, b, l, r);
}

int main() {
	optimize_io
	int op, l, r;
	cin >> N >> M;
	init();
	build(0, 0, N - 1);

	FOR(i, 0, M) {
		cin >> op >> l >> r;

		if (op == 0) {
			updateRange(0, 0, N - 1, l - 1, r - 1);
		} else {
			cout << queryRange(0, 0, N - 1, l - 1, r - 1) << '\n';
		}
	}
	return 0;
}
