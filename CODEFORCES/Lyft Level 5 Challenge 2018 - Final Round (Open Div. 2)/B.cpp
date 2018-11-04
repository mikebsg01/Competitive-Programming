#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define INF -1
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef set<int> seti;
typedef map<int, int> mapii;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;

int N, M;
vectori A, B;
seti S;
mapii ans;

inline int left(seti::iterator it) {
	if (it == S.begin()) {
		return INF;
	}

	--it;

	return (*it);
}

inline int right(seti::iterator it) {
	++it;

	if (it == S.end()) {
		return INF;
	}

	return (*it);
}

int main() {
	optimize_io
	int n, x, i, l, r, distL, distR;
	seti::iterator it;
	cin >> N >> M;
	n = N + M;

	for (i = 0; i < n; ++i) {
		cin >> x;
		PB(A, x);
	}

	for (i = 0; i < n; ++i) {
		cin >> x;
		PB(B, x);
		
		if (x == 1) {
			INS(S, A[i]);
		}
	}

	for (i = 0; i < n; ++i) {
		if (B[i] == 0) {
			INS(S, A[i]);
			it = LOWER(S, A[i]);
			l = left(it);
			r = right(it);
			
			if (l != INF and r != INF) {
				distL = A[i] - l;
				distR = r - A[i];

				if (distL <= distR) {
					++ans[l];
				} else {
					++ans[r];
				} 
			} else if (l != INF) {
				++ans[l];
			} else {
				++ans[r];
			}

			ERASE(S, A[i]);
		}
	}

	for (i = 0; i < n; ++i) {
		if (B[i] == 1) {
			cout << ans[A[i]] << ' ';
		}
	}
	cout << '\n';
	return 0;
}
