#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define LC(x) (2 * x + 1)
#define RC(x) (2 * x + 2)
#define MAXST 262143
#define MULTIPLE 3
using namespace std;

typedef struct Triple {
	int val[MULTIPLE];
} Triple;

int N, Q;
Triple ST[MAXST];
int lazy[MAXST];

void turn(Triple& t) {
	int tmp = t.val[0];
	t.val[0] = t.val[1];
	t.val[1] = t.val[2];
	t.val[2] = tmp;
}

void calc(int node) {
	FOR(i, 0, MULTIPLE) {
		ST[node].val[i] = ST[LC(node)].val[i] + ST[RC(node)].val[i];
	}
}

void build(int node, int a, int b) {
	if (a == b) {
		ST[node].val[0] = 1;
		return;
	}

	int m = (a + b) / 2;

	build(LC(node), a, m);
	build(RC(node), m + 1, b);
	calc(node);
}

void updateRange(int node, int a, int b, int l, int r) {
	int t = lazy[node] % MULTIPLE;

	if (t > 0) {
		FOR(i, 0, t) {
			turn(ST[node]);
		}

		if (a != b) {
			lazy[LC(node)] += t;
			lazy[RC(node)] += t;
		}

		lazy[node] = 0;
	}

	if (a > b or b < l or a > r) {
		return;
	} else if (l <= a and b <= r) {
		turn(ST[node]);

		if (a != b) {
			lazy[LC(node)] += 1;
			lazy[RC(node)] += 1;
		}
		return;
	}

	int m = (a + b) / 2;
	updateRange(LC(node), a, m, l, r);
	updateRange(RC(node), m + 1, b, l, r);
	calc(node);
}

int queryRange(int node, int a, int b, int l, int r) {
	if (a > b or b < l or a > r) {
		return 0;
	}

	int t = lazy[node] % MULTIPLE;

	if (t > 0) {
		FOR(i, 0, t) {
			turn(ST[node]);
		}

		if (a != b) {
			lazy[LC(node)] += t;
			lazy[RC(node)] += t;
		}

		lazy[node] = 0;
	}

	if (l <= a and b <= r) {
		return ST[node].val[0];
	}

	int m = (a + b) / 2;
	return queryRange(LC(node), a, m, l, r) + queryRange(RC(node), m + 1, b, l, r);
}

int main() {
	optimize_io
	int op, l, r;
	cin >> N >> Q;
	build(0, 0, N - 1);

	FOR(i, 0, Q) {
		cin >> op >> l >> r;

		if (op) {
			cout << queryRange(0, 0, N - 1, l, r) << '\n';
		} else {
			updateRange(0, 0, N - 1, l, r);
		}
	}
	return 0;
}
