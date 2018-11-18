#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define dddbl(x) cout << #x << ": " << fixed << setprecision(9) << x << endl;
#define ddp(x) cout << #x << ".X: " << x.first << " " << #x << ".Y: " << x.second << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define MAXN 105
#define EPS 1e-8
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<ui, ui> Pair;
typedef pair<Pair, Pair> Quart;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef vector<double> vectordbl;
typedef set<int> seti;
typedef set<Pair> setPair;
typedef map<int, int> mapi;

ui T, N;
ulli M;
vectori factors;
Pair P[MAXN];
bool vis[MAXN];
lli ans;

lli fact(ui n) {
	lli f = 1;
	for (ui i = 2; i <= n; ++i) {
		f *= i;
	}
	return f;
}

void getFactors(ui n) {
	ui i;
	factors.clear();

	if (n >= 1) {
		PB(factors, 1);
	}
	
	for (i = 2; i * i <= n; ++i) {
		if ((n % i) == 0) {
			if ((i * i) == n) {
				PB(factors, i);
			} else {
				PB(factors, n / i);
				PB(factors, i);
			}
		}
	}

	if (n != 1) {
		PB(factors, n);
	}

	sort(ALL(factors));
	M = factors.size();
	//dd(M);
	//dd(fact(M));
}

void backtrack(ulli lvl) {
	if (lvl == M) {
		++ans;
		return;
	}
 
	for (ui i = 0; i < M; ++i) {
		if (lvl > 0 and (P[lvl - 1].Y + 1) == i) {
			continue;
		}

		if (! vis[i]) {
			vis[i] = true;
			P[lvl].X = factors[i];
			P[lvl].Y = i;
			backtrack(lvl + 1);
			vis[i] = false;
		}
	}
}

int main() {
	optimize_io
	cin >> T;
	while (T--) {
		cin >> N;
		ans = 0;
		getFactors(N);
		backtrack(0);
		cout << ans << endl;
	}
	return 0;
}
