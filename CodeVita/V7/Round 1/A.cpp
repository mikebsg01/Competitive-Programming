#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define dddbl(x) cout << #x << ": " << fixed << setprecision(9) << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define MAXN 13
#define EPS 1e-8
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<double> vectordbl;
typedef set<int> seti;
typedef map<int, int> mapi;


ui N;
double D;
vectordbl A;
ui P[MAXN], p;
double limitIzq, limitDer;
vectori ans;
seti off;

bool isSolution() {
	ui i;
	int idx;
	double pos, t, right, left, a, b;

	for (i = 0; i < p; ++i) {
		idx = ((int) P[i]) - 1;
		pos = (double) idx;
		t = A[idx];

		if (i > 0) {
			left = (pos * D) - (t / 2.0);
			
			if (left > right) {
				return false;
			}
		}

		left = (pos * D) - (t / 2.0);
		right = (pos * D) + (t / 2.0);

		if (i > 0) {
			a = min(a, left);
			b = max(b, right);
		} else {
			a = left;
			b = right;
		}
	}

	if (a <= limitIzq and b >= limitDer) {
		return true;
	}

	return false;
}

void backtrack(ui lvl) {
	if (lvl > (N + 1)) {
		return;
	}

	if (isSolution()) {
		if (ans.size() > 0) {
			if (p < ans.size()) {
				ans.clear();
	
				for (ui i = 0; i < p; ++i) {
					PB(ans, P[i]);
				}
			}
		} else { 
			for (ui i = 0; i < p; ++i) {
				PB(ans, P[i]);
			}
		}	
	}

	P[p++] = lvl;
	backtrack(lvl + 1);
	P[--p] = 0;
	backtrack(lvl + 1);
}

int main() {
	optimize_io
	ui i;
	ulli n;
	double x;
	cin >> N;
	cin >> D;
	limitIzq = 0;
	limitDer = ((double) (N - 1)) * D;
	
	for (i = 0; i < N; ++i) {
		cin >> x;
		PB(A, x);
		INS(off, i + 1);
	}

	backtrack(1);
	n = ans.size();

	if (n == 0) {
		cout << "INSUFFICIENT LAMPS\n";
	} else {
		sort(ALL(ans));

		cout << n << '\n';
		for (i = 0; i < n; ++i) {
			if (i > 0) {
				cout << ' ';
			}

			cout << ans[i];
			ERASE(off, ans[i]);
		}
		cout << '\n';
		i = 0;
		for (seti::iterator it = off.begin(); it != off.end(); ++it) {
			if (i > 0) {
				cout << ' ';
			}

			cout << (*it);
			++i;
		}
		cout << '\n';
	}
	return 0;
}
