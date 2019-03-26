#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for (int i = a; i > b; --i)
#define CFOR(i,a,b,c) for (int i = a; i != b; i += c)
#define PB(s,x) s.push_back(x)
#define PUSH(s,x) s.push(x)
#define MP make_pair
#define X first
#define Y second
#define SZ size()
#define ALL(s) s.begin(), s.end()
#define LC(x) ((x << 1) + 1)
#define RC(x) ((x << 1) + 2)
#define INF INT_MIN
using namespace std;
typedef vector<int> vectori;

class Node {
public:
	int	sum = INF,
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
		n = (1 << logn) - 1;

	ST.assign(n, Node(0, 0, 0, 0));
}

void merge(Node& node, Node& lc, Node& rc) {
	node.sum	= lc.sum + rc.sum;
	node.prefixSum	= max(lc.prefixSum, lc.sum + rc.prefixSum);
	node.suffixSum	= max(rc.suffixSum, lc.suffixSum + rc.sum);

	node.maxSum	=	max(node.prefixSum, 
					max(node.suffixSum,
						max(lc.maxSum, 
							max(rc.maxSum, lc.suffixSum + rc.prefixSum)
						)
					)
				);
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
	merge(ST[node], ST[LC(node)], ST[RC(node)]);
}

inline bool isEmpty(const Node& node) {
	return (node.sum == INF and node.prefixSum == INF and 
		node.suffixSum == INF and node.maxSum == INF);
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
		Node result = Node();
		merge(result, p, q);
		return result;
	} else if (isEmpty(p)) {
		return q;
	}

	return p;
}

int main() {
	int x, l, r;
	optimize_io
	cin >> N;

	FOR(i, 0, N) {
		cin >> x;
		PB(A, x);
	}

	init();
	build(0, 0, N - 1);

	cin >> M;

	FOR(i, 0, M) {
		cin >> l >> r;
		cout << query(0, 0, N - 1, l - 1, r - 1).maxSum << '\n';
	}
	return 0;
}
