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
#define MAXN ((int) (1e3+5))
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
typedef vector<string> cvector;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef set<string> cset;
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

int T, N;
cvector A;
cset vis;
bool mark[MAXN];
cset suff[MAXN][MAXN];
int ans;

void addSuffixes(int ai, int aj, const string& a, const string &b) {
	int n = min(a.SZ, b.SZ);
	string t("");

	FOR(int, i, 0, n) {
		t = a[a.SZ - i - 1] + t;

		if (a[a.SZ - i - 1] == b[b.SZ - i - 1]) {
			/*
			dd(ai);
			dd(aj);
			dd(t);
			*/
			INS(suff[ai][aj], t);
			INS(suff[aj][ai], t);
		} else {
			return;
		}
	}
}

void getSuffixes() {
	FOR(int, i, 0, N) {
		FOR(int, j, i + 1, N) {
			addSuffixes(i, j, A[i], A[j]);
		}
	}
}

void backtrack(int idx, int subsets) {
	if (subsets > ans) {
		ans = subsets;
	}

	if (idx == N) {
		return;
	}

	if (!mark[idx]) {
		mark[idx] = true;

		FOR(int, i, idx + 1, N) {
			FOR(cset::iterator, it, suff[idx][i].begin(), suff[idx][i].end()) {
				if (!mark[i] and vis.find((*it)) == vis.end()) {
					mark[i] = true;
					INS(vis, (*it));
					backtrack(idx + 1, subsets + 1);
					ERASE(vis, (*it));
					mark[i] = false;
				}
			}
		}

		mark[idx] = false;
	}

	backtrack(idx + 1, subsets);
}

int main() {
	optimize_io
	string s;

	cin >> T;

	FOR(int, t, 1, T + 1) {
		cin >> N;
		ans = 0;

		FOR(int, i, 0, N) {
			cin >> s;
			PB(A, s);
		}

		getSuffixes();
		backtrack(0, 0);
		cout << "Case #" << t << ": " << (2 * ans) << '\n';

		FOR(int, i, 0, N) {
			FOR(int, j, 0, N) {
				suff[i][j].clear();
			}
		}

		A.clear();
		vis.clear();
		memset(mark, 0, sizeof(mark));
	}
	return 0;
}