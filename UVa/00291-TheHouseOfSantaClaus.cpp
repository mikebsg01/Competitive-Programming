#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define PB(s,x) s.push_back(x)
#define MP make_pair
#define X first
#define Y second
#define SZ size()
#define ALL(s) s.begin(), s.end()
#define NODES 5
using namespace std;
typedef pair<int, int> Pair;
typedef vector<int> vectori;
typedef vector<Pair> vectorPair;

vectori A[NODES + 2], T;
vectorPair E;
bool vis[NODES + 2][NODES + 2];
int P[3 * NODES], p;
vector<vectori> ans;

void add(int src, int dest) {
	PB(A[src], dest);
	PB(E, MP(src, dest));
}

void build() {
	add(1, 2); add(1, 3); add(1, 5);
	add(2, 1); add(2, 5); add(2, 3);
	add(3, 2); add(3, 1); add(3, 5); add(3, 4);
	add(4, 3); add(4, 5);
	add(5, 1); add(5, 2); add(5, 3); add(5, 4);
}

bool isSolution() {
	FOR(i, 0, E.SZ) {
		if (!vis[E[i].X][E[i].Y]) {
			return false;
		}
	}
	return true;
}

void dfs(int src) {
	if (isSolution()) {
		FOR(i, 0, p) {
			PB(T, P[i]);
		}
		PB(ans, T);
		T.clear();
		return;
	}

	int dest, n = A[src].SZ;

	FOR(i, 0, n) {
		dest = A[src][i];

		if (!vis[src][dest]) {
			vis[src][dest] = vis[dest][src] = true;
			P[p++] = dest;
			dfs(dest);
			P[--p] = 0;
			vis[src][dest] = vis[dest][src] = false;
		}
	}
}

int main() {
	optimize_io
	build();
	P[p++] = 1;
	dfs(1);
	sort(ALL(ans));

	FOR(i, 0, ans.SZ) {
		FOR(j, 0, ans[i].SZ) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}
