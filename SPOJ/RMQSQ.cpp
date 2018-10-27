#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INF INT_MAX
using namespace std;
typedef vector<int> vectori;

int N, Q;
vectori A;

class SegmentTree {
private:
	int build(int node, int a, int b) {
		if (a == b) {
			return st[node] = v[a];
		}

		int m = (a + b) / 2;
		return st[node] = min(this->build(2 * node + 1, a, m),
					this->build(2 * node + 2, m + 1, b));
	}

	int query(int node, int a, int b, int l, int r) {
		if (b < l or a > r) {
			return INF;
		}

		if (l <= a and b <= r) {
			return st[node];
		}
	
		int m = (a + b) / 2;
		return min(this->query(2 * node + 1, a, m, l, r),
				this->query(2 * node + 2, m + 1, b, l, r));
	}

public:
	vectori st, v;
	int v_size;

	SegmentTree (vectori& v) {
		this->v_size = v.size();

		int 	logn = (int) ceil(log2(v_size)) + 1,
			n = (1 << logn) - 1;

		this->st.resize(n, INF);
		this->v = vectori(v);
		this->build(0, 0, this->v_size - 1);
	}

	int query(int l, int r) {
		return this->query(0, 0, this->v_size - 1, l, r);
	}
};

int main() {
	optimize_ios
	int i, x, a, b;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> x;
		PB(A, x);
	}

	SegmentTree st(A);

	cin >> Q;
	for (i = 0; i < Q; ++i) {
		cin >> a >> b;
		cout << st.query(a, b) << endl;
	}
	return 0;
}
