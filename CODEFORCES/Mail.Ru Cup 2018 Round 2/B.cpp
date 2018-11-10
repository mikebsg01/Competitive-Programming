#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define MAXN 100005
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;
typedef map<int, int> mapi;

int N, M;
lli L;
vectorlli A;
vectori parent;
vectori rnk;
int disjointSetsCount;

void initDisjointSets(int n) {
	for (int i = 0; i < n; ++i) {
		PB(parent, i);
		PB(rnk, 1);
	}
}

int findRoot(int n) {
	return parent[n] == n ? n : (parent[n] = findRoot(parent[n]));
}

bool isSameSet(int p, int q) {
	return findRoot(p) == findRoot(q);
}

void join(int p, int q) {
	int rootP = findRoot(p), rootQ = findRoot(q);

	if (rootP == rootQ) {
		return;
	}

	--disjointSetsCount;

	if (rnk[rootP] < rnk[rootQ]) {
		parent[rootP] = rootQ;
		rnk[rootQ] += rnk[rootP];
		return;
	}

	parent[rootQ] = rootP;
	rnk[rootP] += rnk[rootQ];
}

int main() {
	optimize_io
	int i, x, p;
	lli d;
	cin >> N >> M >> L;

	initDisjointSets(N);
	
	for (i = 0; i < N; ++i) {
		cin >> x;
		PB(A, x);
	}

	for (i = 0; i < N; ++i) {
		if (A[i] > L) {
			++disjointSetsCount;

			if ((i - 1) >= 0 and A[i - 1] > L) {
				join(i, i - 1);
			}
		}
	}

	for (i = 0; i < M; ++i) {
		cin >> x;

		if (x > 0) {
			cin >> p >> d;
			A[p - 1] += d;

			if (A[p - 1] > L) {
				if ((A[p - 1] - d) <= L) {
					++disjointSetsCount;
				}

				if (p < N and A[p] > L) {
					join(p - 1, p);
				}

				if ((p - 2) >= 0 and A[p - 2] > L) {
					join(p - 1, p - 2);
				}
			}
		} else {
			cout << disjointSetsCount << '\n';
		}
	}
	return 0;
}
