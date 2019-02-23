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
#define MAXN ((int) (1e6+5))
#define MAXK ((int) (1e2+5))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef pair<lli, lli> Pair;
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

lli N, K;
vectorlli A;
vectorPair B;

lli frec(lli x) {
	int idx = upper_bound(ALL(A), x) - A.begin(), i = 0, j = idx - 1;
	lli sum, f = 0;

	while (i < j) {
		sum = A[i] + A[j];

		if (sum == x) {
			++i; --j; ++f;
		} else if (sum < x) {
			++i;
		} else {
			--j;
		}
	}

	return f;
}

int main() {
	optimize_io
	lli x;
	cin >> N >> K;

	FOR(i, 0, N) {
		cin >> x;
		PB(A, x);
	}

	sort(ALL(A));

	FOR(i, 0, K) {
		cin >> x;
		PB(B, MP(-1 * frec(x), x));
	}

	sort(ALL(B));

	FOR(i, 0, K) {
		cout << B[i].Y << ' '  << (-1 * B[i].X) << '\n';
	}
	return 0;
}
