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
lli bit[MAXN];
setPair H;
int ans;

void update(int idx, lli val) {
	idx += 1;

	while (idx <= N) {
		bit[idx] += val;
		idx += (idx & (-idx));
	}
}

lli query(int idx) {
	lli sum = 0;
	idx += 1;

	while (idx > 0) {
		// dd(idx); dd(bit[idx]); cout << endl;
		sum += bit[idx];
		idx -= (idx & (-idx));
	}

	return sum;
}

inline bool isOpen(char c) {
	return c == '(';
}

void init(string s) {
	int i;
	lli add, current = 0;

	for (i = 0; i < N; ++i) {
		add = (isOpen(s[i]) ? 1 : -1);
		update(i, add);
		current += add;
		INS(H, MP(current, i));
	}
}

void solve(string s) {
	init(s);
	int i,  add;
	bool isopen;
	lli sum, open = 0, current = 0, minVal;
	setPair::iterator itMin;

	for (i = 0; i < N; ++i) {
		isopen = isOpen(s[i]);
		add = isopen ? -1 : 1;
		open += add;
		update(i, 2 * add);
		sum = query(N - 1);
		current += -1 * add;
		ERASE(H, MP(current, i));

		if (!H.empty()) {
			itMin = H.begin();
			minVal = (*itMin).X;
		}

		if (sum == 0 and open >= 0 and ((isopen and minVal >= 2) or (!isopen and minVal >= -2) or H.empty())) {
			++ans;
		}

		// dd(i); dd(isopen); dd(minVal); dd(add); dd(open); dd(sum); dd(ans); cout << endl;
		add *= -1;
		open += 2 * add;
		update(i, 2 * add);

		if (open < 0) {
			break;
		}
	}
}

int main() {
	optimize_io
	cin >> N;
	cin >> S;

	if ((N % 2) != 0) {
		cout << "0\n";
		return 0;
	}

	solve(S);
	cout << ans << '\n';
	return 0;
}
