#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef map<int, int> mapi;

int N;
vectorPair A;
int sum;
vectori ans;

struct cmp {
	bool operator()(const Pair& a, const int& x) {
		return a.X < x;
	}

	bool operator()(const int& x, const Pair& a) {
		return x < a.X;
	}
};

int lower(int x) {
	vectorPair::iterator it;
	it = lower_bound(ALL(A), x, cmp());
	return ((int) (it - A.begin()));
}

int upper(int x) {
	vectorPair::iterator it;
	it = upper_bound(ALL(A), x, cmp());
	return ((int) (it - A.begin()));
}

int main() {
	optimize_io
	int i, x, t, n, a, b;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> x;
		PB(A, MP(x, i + 1));
		sum += x;
	}

	sort(ALL(A));

	for (i = 0; i < N; ++i) {
		t = sum - A[i].X;
		x = t / 2;
		
		if ((2 * x) == t) {
			a = lower(x);
			b = upper(x);
			n = b - a;

			if (n > 0 and !(n == 1 and x == A[i].X)) {
				PB(ans, A[i].Y);
			}
		}
	}

	cout << ans.size() << '\n';
	for (i = 0, n = ans.size(); i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}
