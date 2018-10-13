#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << " " << x << endl;
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define NODE X
#define IZQ Y.X
#define DER Y.Y
#define INF -1
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> Node;

int N;
vector<int> A;
vector<Node> T;
vector<int> ans;

int createNode(int val) {
	T.PB(MP(val, MP(INF, INF)));
	return T.size() - 1;
}

int insertNode(int nodeIdx, int val) {
	if (val < T[nodeIdx].NODE) {
		if (T[nodeIdx].IZQ == INF) {
			int idx = createNode(val);
			return T[nodeIdx].IZQ = idx;
		}

		return insertNode(T[nodeIdx].IZQ, val);
	} else {
		if (T[nodeIdx].DER == INF) {
			int idx = createNode(val);
			return T[nodeIdx].DER = idx;
		}

		return insertNode(T[nodeIdx].DER, val);
	}
}

void preorder(int nodeIdx) {
	if (nodeIdx == INF) {
		return;
	}

	ans.PB(T[nodeIdx].NODE);
	preorder(T[nodeIdx].IZQ);
	preorder(T[nodeIdx].DER);
}

int main() {
	optimize_ios

	int i, val, root;

	cin >> N;
	
	for (i = 0; i < N; ++i) {
		cin >> val;
		A.PB(val);
	}

	root = createNode(val);

	for (i = N - 2; i >= 0; --i) {
		insertNode(root, A[i]);
	}

	preorder(root);

	int n = ans.size();

	for (i = 0; i < n; ++i) {
		if (i > 0) {
			cout << ' ';
		}

		cout << ans[i];
	}
	cout << '\n';
	return 0;
}
