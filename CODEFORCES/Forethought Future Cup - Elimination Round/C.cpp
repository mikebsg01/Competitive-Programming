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
#define MAXN ((int) (1e4+5))
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

int T, N, ans;
deque<int> A;

int readDist() {
	int dist;
	cin >> dist;
	ans = max(ans, dist);
	return dist;
}

void init(int a, int b) {
	A.clear();

	FOR(int, i, a, b) {
		PB(A, i + 1);
	}
}

string vectorToString(int n, int without = -1) {
	ostringstream res;

	FOR(int, i, 0, n) {
		if (without == -1 or A[i] != without) {
			if (i > 0) {
				res << ' ';
			}
			
			res << A[i];
		}
	}

	return res.str();
}

int getHalf(bool secondHalf, int n) {
	int m = secondHalf ? (n / 2) : (n - (n / 2));

	FOR(int, i, 0, m) {
		if (secondHalf) {
			A.pop_front();
		} else {
			A.pop_back();
		}
	}

	return n - m;
}

void solve() {
	int m = (N - 1), prevDist, currentDist, x;

	init(1, N);
	cout << 1 << ' ' << m << ' ' << 1 << ' ' << vectorToString(m) << endl;
	prevDist = readDist();

	while (m > 1) {
		cout << 1 << ' ' << (m / 2) << ' ' << 1 << ' ' << vectorToString(m / 2) << endl;
		currentDist = readDist();
		m = getHalf(currentDist != prevDist, m);
	}

	x = A[0];
	init(0, N);
	cout << 1 << ' ' << (N - 1) << ' ' << x << ' ' << vectorToString(N, x) << endl;
	readDist();
}

int main() {
	optimize_io
	cin >> T;

	FOR(int, t, 0, T) {
		cin >> N;
		A.clear();
		ans = 0;
		solve();
		cout << "-1 " << ans << endl;
	}
	return 0;
}