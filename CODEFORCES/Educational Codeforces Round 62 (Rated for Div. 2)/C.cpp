#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for (int i = a; i > b; --i)
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define PUSH(s, x) s.push(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define ISBEGIN(s,it) (it == s.begin())
#define ISEND(s,it) (it == s.end())
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define VUPPER(s,x) upper_bound(ALL(s), x) - s.begin()
#define VLOWER(s,x) lower_bound(ALL(s), x) - s.begin()
#define X first
#define Y second
#define SZ size()
#define MAXN ((int) (1e4+5))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<lli, lli> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef map<int, vectori> cmap;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int N, K;
vectorPair A;
pqlli B;
lli sum, ans;

void insert(lli x) {
	if (B.SZ < K) {
		sum += x;
		PUSH(B, -1 * x);
	} else {
		int t = -1 * B.top();

		if (x > t) {
			sum = sum - t + x;
			B.pop();
			PUSH(B, -1 * x);
		}
	}
}

int main() {
	optimize_io
	lli t, b, f;
	Pair pt;
	cin >> N >> K;

	FOR(i, 0, N) {
		cin >> t >> b;
		PB(A, MP(t, b));
	}

	sort(ALL(A), [](const Pair& a, const Pair& b) {
		return (a.Y != b.Y) ? (a.Y > b.Y) : (a.X < b.X);
	});

	FOR (i, 0, N) {
		insert(A[i].X);
		f = sum * A[i].Y;
		ans = max(ans, f);
	}

	cout << ans << '\n';
	return 0;
}
