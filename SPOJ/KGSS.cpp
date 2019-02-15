#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ALL(s) s.begin(), s.end()
#define PB(s,x) s.push_back(x)
#define MP make_pair
#define SZ size()
#define X first
#define Y second
#define MAXN ((int)(1e5+2))
#define INF -1
using namespace std;
typedef pair<int, int> Pair;
typedef vector<int> vectori;
typedef vector<Pair> vectorPair;

int N, Q;
vectori A;

class SegmentTree {
private:
	Pair getMax(Pair p, Pair q) {
		vectori t = { p.X, p.Y, q.X, q.Y };
		sort(ALL(t));
		return MP(t[2], t[3]);
	}

	Pair build(int node, int a, int b) {
		if (a == b) {
			return this->st[node] = MP(v[a], INF);
		}		

		int m = (a + b) / 2;

		Pair	p = this->build(2 * node + 1, a, m),
			q = this->build(2 * node + 2, m + 1, b);

		return this->st[node] = this->getMax(p, q);
	}

	Pair query(int node, int a, int b, int l, int r) {
		if (b < l or a > r) {
			return MP(INF, INF);
		}

		if (l <= a and b <= r) {
			return this->st[node];
		}

		int m = (a + b) / 2;

		Pair	p = this->query(2 * node + 1, a, m, l, r),
			q = this->query(2 * node + 2, m + 1, b, l, r);

		return this->getMax(p, q);
	}

	void update(int node, int a, int b, int idx, int val) {
		if (a == b) {
			this->v[idx] = val;
			this->st[node] = MP(val, INF);
			return;
		}

		int m = (a + b) / 2;

		if (idx >= a and idx <= m) {
			this->update(2 * node + 1, a, m, idx, val);
		} else {
			this->update(2 * node + 2, m + 1, b, idx, val);
		}

		Pair	p = this->st[2 * node + 1],
			q = this->st[2 * node + 2];

		this->st[node] = this->getMax(p, q);
	}

public:
	vectorPair st;
	vectori v;
	int v_size;

	SegmentTree(vectori& v) {
		this->v_size = v.SZ;

		int	logn = (int) ceil(log2(this->v_size)) + 1,
			n = (1 << logn) - 1;

		this->st.assign(n, MP(INF, INF));
		this->v = vectori(v);
		this->build(0, 0, this->v_size - 1);
	}

	int query(int l, int r) {
		Pair t = this->query(0, 0, this->v_size - 1, l, r);
		return t.X + t.Y;
	}

	void update(int idx, int val) {
		this->update(0, 0, this->v_size - 1, idx, val);	
	}
};

int main() {
	optimize_io
	int x, y;
	char c;
	cin >> N;

	FOR(i, 0, N) {
		cin >> x;
		PB(A, x);
	}

	SegmentTree st(A);
	cin >> Q;

	FOR(i, 0, Q) {
		cin >> c >> x >> y;

		if (c == 'Q') {
			cout << st.query(x - 1, y - 1) << '\n';
		} else if (c == 'U') {
			st.update(x - 1, y);
		}
	}
	return 0;
}
