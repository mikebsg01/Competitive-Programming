#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(t,i,a,b) for(t i = a; i != b; ++i)
#define RFOR(t,i,a,b) for(t i = a; i != b; --i)
#define PB(s,x) s.push_back(x)
#define LC(x) ((x << 1) + 1)
#define RC(x) ((x << 1) + 2)
#define INF INT_MIN
using namespace std;
typedef vector<int> vectori;

class Node {
public:
	int sum = INF,
		prefixSum = INF,
		suffixSum = INF,
		maxSum = INF;

	Node() {}

	Node(int _sum, int _prefixSum, int _suffixSum, int _maxSum) :
		sum(_sum),
		prefixSum(_prefixSum),
		suffixSum(_suffixSum),
		maxSum(_maxSum) {}
};

int N, M;
vectori A;
vector<Node> ST;

void init() {
	int	logn = ceil(log2(N)) + 1,
		size = (1 << logn) - 1;

	ST.assign(size, Node(0, 0, 0, 0));
}

Node merge(Node& lc, Node& rc) {
	Node parent;

	parent.sum = lc.sum + rc.sum;
	parent.prefixSum = max(lc.prefixSum, lc.sum + rc.prefixSum);
	parent.suffixSum = max(rc.suffixSum, lc.suffixSum + rc.sum);

	parent.maxSum = max(parent.prefixSum,
						max(parent.suffixSum,
							max(lc.maxSum,
								max(rc.maxSum, lc.suffixSum + rc.prefixSum)
							)
						)
					);

	return parent;
}

void build(int node, int a, int b) {
	if (a == b) {
		int t = A[a];
		ST[node] = Node(t, t, t, t);
		return;
	}

	int m = (a + b) >> 1;
	build(LC(node), a, m);
	build(RC(node), m + 1, b);
	ST[node] = merge(ST[LC(node)], ST[RC(node)]);
}

inline bool isEmpty(const Node& node) {
	return  node.sum == INF and node.prefixSum == INF and 
			node.suffixSum == INF and node.maxSum == INF;
}

Node query(int node, int a, int b, int l, int r) {
	if (b < l or r < a) {
		return Node(INF, INF, INF, INF);
	} else if (l <= a and b <= r) {
		return ST[node];
	}

	int m = (a + b) >> 1;
	Node	p = query(LC(node), a, m, l, r),
			q = query(RC(node), m + 1, b, l, r);

	if (! isEmpty(p) and ! isEmpty(q)) {
		return merge(p, q);
	} else if (isEmpty(p)) {
		return q;
	}
	return p;
}

void update(int node, int a, int b, int pos, int val) {
	if (a == b) {
		ST[node] = Node(val, val, val, val);
		return;
	}

	int m = (a + b) >> 1;

	if (pos <= m) {
		update(LC(node), a, m, pos, val);
	} else {
		update(RC(node), m + 1, b, pos, val);
	}

	ST[node] = merge(ST[LC(node)], ST[RC(node)]);
}

int main() {
	optimize_io
	int x, l, r;
	cin >> N;

	FOR(int, i, 0, N) {
		cin >> x;
		PB(A, x);
	}

	init();
	build(0, 0, N - 1);

	cin >> M;

	FOR(int, i, 0, M) {
		cin >> x >> l >> r;

		if (x > 0) {
			cout << query(0, 0, N - 1, l - 1, r - 1).maxSum << '\n';
		} else {
			update(0, 0, N - 1, l - 1, r);
		}
	}
	return 0;
}