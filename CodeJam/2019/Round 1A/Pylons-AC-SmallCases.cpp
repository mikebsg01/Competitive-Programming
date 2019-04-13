#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i != b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i != b; --i)
#define CFOR(t,i,a,b,c) for (t i = a; i < b; i += c)
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define PUSH(s, x) s.push(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define SZ size()
#define MAXN ((int) (20+5))
#define EPS (1e-8)
#define INF -1
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> Pair;
typedef pair<lli, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef pair<Pair, string> cPair;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef vector<Tern> vectorTern;
typedef vector<string> cvector;
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

int T, R, C;
int vis[MAXN][MAXN];
bool solved;
Pair P[MAXN * MAXN]; int p;

void printMap() {
	FOR(int, i, 0, R) {
		FOR(int, j, 0, C) {
			cout << vis[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

inline bool isInvalid(int y1, int x1, int y2, int x2) {
	return (y1 == y2) or (x1 == x2) or ((y1 - x1) == (y2 - x2)) or ((y1 + x1) == (y2 + x2));
}

void backtrack(int y, int x, int counter, int testcase) {
	if (solved) {
		return;
	} else if (counter == (R * C)) {
		solved = true;
		cout << "Case #" << testcase << ": POSSIBLE\n";

		// printMap();

		FOR(int, i, 0, p) {
			cout << (P[i].X + 1) << ' ' << (P[i].Y + 1) << '\n';
		}
		return;
	}
	
	FOR(int, i, 0, R) {
		FOR(int, j, 0, C) {
			if (!vis[i][j] and !isInvalid(y, x, i, j)) {
				vis[i][j] = counter + 1;
				P[p++] = MP(i, j);
				backtrack(i, j, counter + 1, testcase);
				P[--p] = MP(INF, INF);
				vis[i][j] = 0;
			}
		}
	}
}

void solve(int testcase) {
	FOR(int, i, 0, R) {
		FOR(int, j, 0, C) {
			vis[i][j] = 1;
			P[p++] = MP(i, j);
			backtrack(i, j, 1, testcase);
			P[--p] = MP(INF, INF);
			vis[i][j] = 0;

			if (solved) {
				return;
			}
		}
	}
	cout << "Case #" << testcase << ": IMPOSSIBLE\n";
}

int main() {
	optimize_io

	cin >> T;

	FOR(int, t, 1, T + 1) {
		cin >> R >> C;
		memset(vis, 0, sizeof(vis));
		solved = false;
		p = 0;
		solve(t);
	}
	return 0;
}