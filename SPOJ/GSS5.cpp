#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ":" << x << endl;
#define FOR(t,i,a,b) for(t i = a; i != b; ++i)
#define PB(s,x) s.push_back(x)
#define LC(x) ((x << 1) + 1)
#define RC(x) ((x << 1) + 2)
#define INF INT_MIN
using namespace std;
typedef long long int lli;
typedef vector<lli> vectori;

class Node {
public:
	lli sum = INF,
		prefixSum = INF,
		suffixSum = INF,
		maxSum = INF;

	Node() {}

	Node(int _sum) :
		sum(_sum),
		prefixSum(_sum),
		suffixSum(_sum),
		maxSum(_sum) {}
};

int T, N, M;
vectori A;
vector<Node> ST;

void init() {
	int logn = ceil(log2(N)) + 1,
		size = (1 << logn) - 1;

	ST.assign(size, Node(0));
}

Node merge(Node& lc, Node& rc) {
	Node parent;

	parent.sum = lc.sum + rc.sum;
	parent.prefixSum = max(lc.prefixSum, lc.sum + rc.prefixSum);
	parent.suffixSum = max(rc.suffixSum, lc.suffixSum + rc.sum);
	
	parent.maxSum = max(lc.maxSum,
						max(rc.maxSum,
							lc.suffixSum + rc.prefixSum
						)
					);

	return parent;
}

void build(int node, int a, int b) {
	if (a == b) {
		ST[node] = Node(A[a]);
		return;
	}

	int m = (a + b) >> 1;
	build(LC(node), a, m);
	build(RC(node), m + 1, b);
	ST[node] = merge(ST[LC(node)], ST[RC(node)]);
}

inline bool isEmpty(const Node& node) {
	return node.prefixSum == INF and node.suffixSum and node.maxSum == INF;
}

Node query(int node, int a, int b, int l, int r) {
	if (b < l or r < a or l > r) {
		Node t = Node();
		t.sum = 0;
		return t;
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

Node q(int l, int r) {
	return query(0, 0, N - 1, l - 1, r - 1);
}

int main() {
	optimize_io
	lli x;
	int x1, y1, x2, y2;
	cin >> T;

	FOR(int, t, 0, T) {
		cin >> N;
		A.clear();

		FOR(int, i, 0, N) {
			cin >> x;
			PB(A, x);
		}

		init();
		build(0, 0, N - 1);

		cin >> M;

		FOR(int, i, 0, M) {
			cin >> x1 >> y1 >> x2 >> y2;
			
			if (y1 < x2) {
				cout << q(x1, y1).suffixSum + q(y1 + 1, x2 - 1).sum + q(x2, y2).prefixSum << '\n';
			} else {
				cout << max(q(x2, y1).maxSum,
							max(q(x1, x2 - 1).suffixSum + q(x2, y2).prefixSum,
								q(x1, y1).suffixSum + q(y1 + 1, y2).prefixSum
							)
						) << '\n';
			}
		}
	}
	return 0;
}