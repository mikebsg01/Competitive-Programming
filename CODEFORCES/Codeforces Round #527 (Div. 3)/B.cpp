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
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;

lli T, N;
priority_queue<int> Q;
lli ans;

int main() {
	optimize_io
	int i, x, a, b;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> x;
		PUSH(Q, x);
	}

	while (!Q.empty()) {
		a = Q.top(); Q.pop();
		b = Q.top(); Q.pop();
		ans += abs(a - b);
	}

	cout << ans << '\n';
	return 0;
}
