#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define MAXN 1002
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;

int N, R;
bool H[MAXN];
vector<P> A;

inline bool intercept(int aDer, int bIzq) {
	return (aDer + 1) >= bIzq;
}

bool isSolution() {
	int i, n = A.size(), start = -1, end = -1;

	if (n > 0) {
		start = A[0].X;
		end = A[n - 1].Y;
	}

	if (start != 0 or end != (N - 1)) {
		return false;
	}

	for (i = 1; i < n; ++i) {
		if (!intercept(A[i - 1].Y, A[i].X)) {
			return false;
		}
	}

	return true;
}	

bool hasSolution() {
	int i, l, r;

	for (i = 0; i < N; ++i) {
		if (H[i]) {
			l = i - R + 1;
			r = i + R - 1;
			l = (l < 0) ? 0 : l;
			r = (r >= N) ? (N - 1) : r;

			A.PB(MP(l, r));
		}
	}

	sort(ALL(A));
	return isSolution();
}

int findSolution() {
	if (!hasSolution()) {
		return -1;
	}

	int i, n = A.size(), prev = 0, aDer = -1, current, ans = 0;

	if (n > 0) {
		while ((aDer + 1) < N) {
			for (i = prev; i < n; ++i) {
				if (intercept(aDer, A[i].X)) {
					current = i;
				} else {
					break;
				}
			}

			prev = current;
			aDer = A[prev].Y;
			++ans;
		}
	}

	return ans;
}

int main() {
	optimize_ios

	int i;

	cin >> N >> R;

	for (i = 0; i < N; ++i) {
		cin >> H[i];
	}

	cout << findSolution() << '\n';
	return 0;
}
