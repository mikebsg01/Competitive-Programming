#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 702
#define M 0
#define B 1
#define N_MOVS 2
#define PB push_back
#define EM emplace
#define EB emplace_back
#define MP make_pair
#define X first
#define Y second
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<double, pii> pdpii;

int N;
double T[MAXN][MAXN][2];
int MOV_Y[N_MOVS] = {0, 1};
int MOV_X[N_MOVS] = {1, 0};
vector<int> parent, rnk;
int disjointSetsCount;
vector<pdpii> interceptionsX;
int ans;

void initDisjointSets(int n) { /* O(n) */
	disjointSetsCount = n, ans = n > 0 ? 1 : 0;
	
	for (int i = 0; i < n; ++i) {
		parent.PB(i);
		rnk.PB(1);
	}
}

int findRoot(int n) { /* ≈ O(log n) */
	return parent[n] == n ? n : findRoot(parent[n]); /* VERY IMPORTANT: Don't update the parent like this: 
								parent[n] = findRoot(parent[n]) */
}

bool isSameSet(int p, int q) { /* ≈ O(2 log n) */
	return findRoot(p) == findRoot(q);
}

pib join(int p, int q) { /* ≈ O(2 log n)  */
	int rootP = findRoot(p), rootQ = findRoot(q);

	if (rootP == rootQ) {
		return MP(rnk[rootP], false);
	} 

	--disjointSetsCount;

	if (rnk[rootP] < rnk[rootQ]) {
		parent[rootP] = rootQ;
		rnk[rootQ] += rnk[rootP];
		ans = max(ans, rnk[rootQ]);
		return MP(rnk[rootQ], true);
	}

	parent[rootQ] = rootP;
	rnk[rootP] += rnk[rootQ];
	ans = max(ans, rnk[rootP]);
	return MP(rnk[rootP], true);
}

pib disjoin(int p, int q) { /* ≈ O(2 log n) */
	int rootP = findRoot(p), rootQ = findRoot(q);

	if (rootP != rootQ) {
		return MP(rnk[rootP], false);
	}

	++disjointSetsCount;

	if (rnk[p] < rnk[q]) {
		parent[p] = p;
		rnk[q] -= rnk[p];
		return MP(rnk[p], true);
	}

	parent[q] = q;
	rnk[p] -= rnk[q];
	return MP(rnk[q], true);
}

inline bool isInside(int y, int x) {
	return y >= 0 and y < N and x >= 0 and x < N;
}

inline int getIndex(int y, int x) {
	return (y * N) + x;
}

void generateSetsOfSimilarLines(int y1, int x1, int  y2, int x2) { /* ≈ O(2 log n) */
	if (!isInside(y2, x2)) {
		return;	
	}

	double	m1 = T[y1][x1][M], b1 = T[y1][x1][B],
		m2 = T[y2][x2][M], b2 = T[y2][x2][B],
		a = b1 - b2,
		b = m2 - m1,
		x;

	int idxP = getIndex(y1, x1), idxQ = getIndex(y2, x2);

	if (b == 0 and a == b) { /* For Parallel Lines with Infinite Interceptions */
		join(idxP, idxQ);
	} else if (b != 0) { /* It validates Parallel Lines that don't intercept */
		x = a / b;

		if (x >= 0) {
			interceptionsX.EB(x, MP(idxP, idxQ));
		}
	}
}

void printRanks() {
	int i, j;

	cout << "Rank:\n";

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			cout << getIndex(i, j) << ' ';
	cout << '\n';

        for (i = 0; i < N; ++i)
                 for (j = 0; j < N; ++j)
                         cout << rnk[getIndex(i, j)] << ' ';
        cout << '\n';

}

int main() {
	optimize_ios

	int i, j, k, x, n, rootP, rootQ;
	pdpii tmp;
	pib res;
	stack<pii> unitedSets;

	cin >> N;
	initDisjointSets(N * N);

	for (i = 1; i > -1; --i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				cin >> x;
				T[j][k][i] = x;
			}
		}
	}

	/* complexity ≈ O((N * N) * (2 log (N * N))) */
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N_MOVS; ++k) {
				generateSetsOfSimilarLines(i, j, i + MOV_Y[k], j + MOV_X[k]);
			}
		}
	}

	sort(ALL(interceptionsX));

	n = interceptionsX.size();
	/* printRanks(); */

	for (i = 0; i < n; ++i) { /* Travel of the Interceptions on the X axis (See as a Sequence of Events) */
		tmp = interceptionsX[i];
		rootP = findRoot(tmp.Y.X), rootQ = findRoot(tmp.Y.Y);
		res = join(rootP, rootQ);
		/* printRanks();*/

		if (res.Y) {
			unitedSets.EM(rootP, rootQ);
		}

		if ((i + 1) == n or tmp.X != interceptionsX[i + 1].X) {
			while (!unitedSets.empty()) {
				tmp.Y = unitedSets.top();
				disjoin(tmp.Y.X, tmp.Y.Y);
				unitedSets.pop();
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
