#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define PB(s,x) s.push_back(x)
#define SZ size()
#define ALL(s) s.begin(), s.end()
#define LC(x) (2 * x + 1)
#define RC(x) (2 * x + 2)
#define MAXN ((int)(1e5+2))
#define MAX_ST_SIZE 262143
using namespace std;
typedef vector<int> vectori;

int N, M, A[MAXN];
vectori ST[MAX_ST_SIZE];

void build(int node, int a, int b) {
	if (a == b) {
		PB(ST[node], A[a]);
		return;
	}

	int m = (a + b) / 2;

	build(LC(node), a, m);
	build(RC(node), m + 1, b);

	vectori &merged = ST[node], &left = ST[LC(node)], &right = ST[RC(node)];
	int i = 0, j = 0, ls = left.SZ, rs = right.SZ;

	while (i < ls or j < rs) {
		if (i < ls and j < rs) {
			if (left[i] <= right[j]) {
				PB(merged, left[i++]);
			} else {
				PB(merged, right[j++]);
			}
		} else if (i < ls) {
			PB(merged, left[i++]);
		} else if (j < rs) {
			PB(merged, right[j++]);
		}
	}
}

int query(int node, int a, int b, int l, int r, int x) {
	if (b < l or a > r) {
		return 0;
	} else if (l <= a and b <= r) {
		int idx = upper_bound(ALL(ST[node]), x) - ST[node].begin();
		return idx;
	}

	int m = (a + b) / 2;
	return query(LC(node), a, m, l, r, x) + query(RC(node), m + 1, b, l, r, x);
}

int binary(int a, int b, int l, int r, int k) {
	int m, v;
	while (a < b) {
		m = (a + b) / 2,
		v = query(0, 0, N - 1, l, r, ST[0][m]);

		if (v >= k) {
			b = m;
		} else {
			a = m + 1;
		}
	}
	return ST[0][a];
}

int main() {
	optimize_io
	int l, r, k;
	cin >> N >> M;

	FOR(i, 0, N) {
		cin >> A[i];
	}

	build(0, 0, N - 1);

	FOR(i, 0, M) {
		cin >> l >> r >> k;
		cout << binary(0, N - 1, l - 1, r - 1, k) <<  '\n';
	}
	return 0;
}
