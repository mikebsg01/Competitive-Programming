#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define INS(s,x) s.insert(x)
#define PB(s,x) s.push_back(x)
#define MP make_pair
#define X first
#define Y second
#define SZ size()
using namespace std;
typedef pair<int, int> Pair;

int N, M;
int X[2] = { INT_MAX, 0 }, Y[2] = { INT_MAX, 0 };
set<Pair> S;

int main() {
	optimize_io
	char c;
	cin >> N >> M;

	FOR(i, 0, N) {
		FOR(j, 0, M) {
			cin >> c;
			if (c == '*') {
				INS(S, MP(j, i));
				X[0] = min(X[0], j);
				X[1] = max(X[1], j);
				Y[0] = min(Y[0], i);
				Y[1] = max(Y[1], i);
			}
		}
	}

	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			if (S.count(MP(X[i], Y[j])) == 0) {
				cout << (Y[j] + 1) << ' ' << (X[i] + 1) << '\n';
				return 0;
			}
		}
	}
	return 0;
}
