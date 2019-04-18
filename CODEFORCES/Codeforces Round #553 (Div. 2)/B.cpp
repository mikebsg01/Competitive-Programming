#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i != b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i != b; --i)
#define CFOR(t,i,a,b,c) for (t i = a; i < b; i += c)
#define VUPPER(s,x) upper_bound(ALL(s), x) - s.begin()
#define VLOWER(s,x) lower_bound(ALL(s), x) - s.begin()
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define PUSH(s, x) s.push(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define SZ size()
#define MAXN ((int) (500+5))
#define EPS (1e-8)
#define INF -1
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<lli, lli> Pair;
typedef pair<lli, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef pair<Pair, string> cPair;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef vector<Tern> vectorTern;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef map<lli, char> cmap;
typedef queue<int> qi;
typedef queue<lli> qlli;
typedef queue<Pair> qPair;
typedef queue<cPair> cq;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int N, M, T[MAXN][MAXN], P[MAXN];

bool allRowEqual(int row) {
	int e = T[row][0];

	FOR(int, i, 1, M) {
		if (T[row][i] != e) {
			return false;
		}
	}

	return true;
}

bool isImpossible() {
	int res = 0;
	FOR(int, i, 0, N) {
		res ^= T[i][0];
	}

	if (res > 0) {
		return false;
	}

	FOR(int, i, 0, N) {
		if (! allRowEqual(i)) {
			return false;
		}
	}

	return true;
}

void solve() {
	int res = 0;

	FOR(int, i, 0, N) {
		P[i] = 0;
		res ^= T[i][0];
	}

	if (res > 0) {
		return;
	}

	FOR(int, i, 0, N) {
		FOR(int, j, 0, M) {
			if (T[i][P[i]] != T[i][j]) {
				P[i] = j;
				return;
			}
		}
	}
}

int main() {
	optimize_io
	
	cin >> N >> M;

	FOR(int, i, 0, N) {
		FOR(int, j, 0, M) {
			cin >> T[i][j];
		}
	}

	if (isImpossible()) {
		cout << "NIE\n";
	} else {
		solve();
		cout << "TAK\n";

		FOR(int, i, 0, N) {
			if (i > 0) {
				cout << ' ';
			}

			cout << (P[i] + 1);
		}

		cout << '\n';
	}
	return 0;
}