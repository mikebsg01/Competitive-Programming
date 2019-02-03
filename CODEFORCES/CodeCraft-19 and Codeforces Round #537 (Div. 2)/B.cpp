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
#define SZ size()
#define X first
#define Y second
#define MAXN ((int) (1e6))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;
typedef priority_queue<lli, vector<lli>, greater<lli> > minHeap;

lli N, K, M, S;
minHeap Q;
ld ans;

ld getAverage() {
	lli maxIncrease, maxSum;
	ld average;

	maxIncrease = (lli) ((K >= M) ? M : min((ld) N, (ld) M / K) * K);
	maxSum = S + maxIncrease;
	average = (ld) maxSum / N;
	return average;
}

void solve() {
	lli t;
	ans = max(ans, getAverage());

	while (Q.SZ > 1 and M > 0) {
		t = Q.top(); Q.pop();
		S -= t;
		--N;
		--M;
		ans = max(ans, getAverage());
	}
}

int main() {
	optimize_io
	lli x;
	cin >> N >> K >> M;

	FOR(i, 0, N) {
		cin >> x;
		PUSH(Q, x);
		S += x;
	}

	solve();
	cout << fixed << setprecision(15) << ans << '\n';
	return 0;
}
