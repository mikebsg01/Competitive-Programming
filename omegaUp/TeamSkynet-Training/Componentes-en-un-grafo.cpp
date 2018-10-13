#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << " : " << x << endl;
#define MAXN 30002
#define MP make_pair
#define X first
#define Y second
using namespace std;
typedef pair<bool, int> P;

int N;
int parent[MAXN];
int rnk[MAXN];
int ansMin = 1, ansMax = 1;

void initDisjointSets(int n) {
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		rnk[i] = 1;
	}
}

int findRoot(int n) {
	return parent[n] == n ? n : (parent[n] = findRoot(parent[n]));
}

P join(int p, int q) {
	p = findRoot(p), q = findRoot(q);

	if (p == q) {
		return MP(false, rnk[p]);
	}

	if (rnk[p] < rnk[q]) {
		rnk[q] += rnk[p];
		parent[p] = q;
		return MP(true, rnk[q]);
	}

	rnk[p] += rnk[q];
	parent[q] = p;
	return MP(true, rnk[p]);
}

int main() {
	optimize_ios

	int i, x, y;

	cin >> N;

	initDisjointSets(2 * N);

	for (i = 0; i < N; ++i) {
		cin >> x >> y;
		join(x - 1, y - 1);
	}

	for (i = 0; i < (2 * N); ++i) {
		x = findRoot(i);
	
		if (rnk[x] > 1) {
			ansMax = max(ansMax, rnk[x]);

			if (ansMin == 1) {
				ansMin = rnk[x];
			}

			ansMin = min(ansMin, rnk[x]);
		}
	}

	cout << ansMin << ' ' << ansMax << '\n';
	return 0;
}
