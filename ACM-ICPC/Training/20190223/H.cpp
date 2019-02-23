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
#define SZ size()
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

int N;
ulli t[4];
vectori A;
ulli ans;

inline ulli f() {
	return (t[0] * t[0]) + (t[1] * t[1]) + (t[2] * t[2]) + (7 * min(t[0], min(t[1], t[2])));
}

void divide() {
	A.clear();
	PB(A, t[3]); PB(A, 0); PB(A, 0);
	int x = t[3] / 3;
	PB(A, x); PB(A, x); PB(A, t[3] - (2 * x));
	int y = (t[3] - x) / 2;
	PB(A, x); PB(A, y); PB(A, t[3] - x - y);
}

void solve() {
	FOR(i, 0, 3) {
		int idx[] = {0, 1, 2};

		do {
			FOR(j, 0, 3) {
				t[j] += A[idx[j] + (3 * i)];
			}

			ans = max(ans, f());

			FOR(j, 0, 3) {
				t[j] -= A[idx[j] + (3 * i)];
			}
		} while (next_permutation(idx, idx + 3));
	}
}

int main() {
	optimize_io
	cin >> N;

	FOR(i, 0, N) {
		FOR(j, 0, 4) {
			cin >> t[j];
		}

		ans = 0;
		divide();
		solve();
		cout << ans << '\n';
	}
	return 0;
}
