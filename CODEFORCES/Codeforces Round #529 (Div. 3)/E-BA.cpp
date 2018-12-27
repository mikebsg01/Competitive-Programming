#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
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
#define MAXN (((int) (1e6)) + 10)
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef pair<lli, int> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;

lli N;
string S;
lli totalSum;
setPair H;
int ans;

inline bool isOpen(char c) {
	return c == '(';
}

void init(string s) {
	int i;
	lli add;

	for (i = 0; i < N; ++i) {
		add = (isOpen(s[i]) ? 1 : -1);
		totalSum += add;
		INS(H, MP(totalSum, i));
	}
}

void solve(string s) {
	init(s);
	int i,  add;
	bool isopen;
	lli open = 0, current = 0, minVal;
	setPair::iterator itMin;

	for (i = 0; i < N; ++i) {
		isopen = isOpen(s[i]);
		add = isopen ? -1 : 1;
		open += add;
		totalSum += 2 * add;
		current += -1 * add;
		ERASE(H, MP(current, i));

		if (!H.empty()) {
			itMin = H.begin();
			minVal = (*itMin).X;
		}

		if (totalSum == 0 and open >= 0 and ((isopen and minVal >= 2) or (!isopen and minVal >= -2) or H.empty())) {
			++ans;
		}

		add *= -1;
		open += 2 * add;
		totalSum += 2 * add;

		if (open < 0) {
			break;
		}
	}
}

int main() {
	optimize_io
	cin >> N >> S;
	solve(S);
	cout << ans << '\n';
	return 0;
}
