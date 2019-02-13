#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for (int i = a; i > b; --i)
#define PB(s,x) s.push_back(x)
#define ALL(s) s.begin(), s.end()
#define SZ size()
#define MP make_pair
#define X first
#define Y second
#define MAXN ((int)(1e5+2))
using namespace std;
typedef pair<int, int> Pair;
typedef vector<int> vectori;

int T, N;
Pair A[MAXN];

int LIS() {
	int val;
	vectori tail;
	vectori::iterator it;
	PB(tail, A[0].Y);

	FOR(i, 1, N) {
		val = A[i].Y;
		it = upper_bound(ALL(tail), val);

		if (it == tail.end()) {
			PB(tail, val);
		} else {
			*it = val;
		}
	}
	return tail.SZ;
}

int main() {
	optimize_io
	cin >> T;
	
	FOR(i, 0, T) {
		cin >> N;

		FOR(j, 0, N) {
			cin >> A[j].X;
		}

		FOR(j, 0, N) {
			cin >> A[j].Y;
		}

		sort(A, A + N);
		cout << LIS() << '\n';
	}
	return 0;
}
