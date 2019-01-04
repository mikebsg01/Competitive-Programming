#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,b,a) for (int i = (b - 1); i >= a; --i)
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
#define MAXN ((int) (1e6))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<string> vectorstr;
typedef pair<lli, string> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef set<string> setstr;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

lli N;
vectorstr A;
maplli M;
lli ans;

inline bool isOpen(char c) {
	return c == '(';
}

bool isCorrect(string& s) {
	int n = s.size();
	lli v = 0;

	FOR(i, 0, n) {
		v += isOpen(s[i]) ? 1 : -1;

		if (v < 0) {
			return false;
		}
	}

	return v == 0;
}

lli getVal(string& s) {
	int n = s.size();
	lli v = 0;

	FOR(i, 0, n) {
		v += isOpen(s[i]) ? 1 : -1;
	}

	return v;
}

string voltear(string s) {
	int i, n = s.size();
	reverse(s.begin(), s.end());

	for (i = 0; i < n; ++i) {
		s[i] = isOpen(s[i]) ? ')' : '(';
	}

	return s;
}

inline bool match(string a, string b) {
	string t1 = a + b;
	string t2 = b + a;

	return isCorrect(t1) or isCorrect(t2);
}

void solve() {
	maplli::iterator it;
	string sa, sb;
	lli val, minPairs;

	FOR(i, 0, N) {
		cin >> sa;
		sb = voltear(sa);

		if (match(sa, sb)) {
			val = getVal(sa);

			if (M.count(val) > 0) {
				M[val] += 1;
			} else {
				M[val] = 1;
			}
		}
	}

	if (M.count(0) > 0) {
		ans = M[0] / 2;
		ERASE(M, 0);
	}

	for (it = M.begin(); it != M.end(); ++it) {
		val = it->first;

		if (M.count(-1 * val) > 0) {
			minPairs = min(M[val], M[-1 * val]);
			ans += minPairs;
			M[val] -= minPairs;
			M[-1 * val] -= minPairs;
		}
	}
}

int main() {
	optimize_io
	cin >> N;
	solve();
	cout << ans << '\n';
	return 0;
}
