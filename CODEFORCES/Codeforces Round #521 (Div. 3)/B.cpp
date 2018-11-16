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
typedef vector<bool> vectorbl;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef map<int, int> mapi;

int N;
vectorbl A;
vectorPair B;
mapi m;
int ans;

inline bool isDisturbed(int idx) {
	return A[idx] == 0 and A[idx - 1] == A[idx + 1] and A[idx + 1] == 1;
}

bool isSolution() {
	for (int i = 1; i < (N - 1); ++i) {
		if (isDisturbed(i)) {
			return false;
		}
	}
	return true;
}

int main() {
	optimize_io
	int i, n, t;
	bool x;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> x;
		PB(A, x);
	}

	for (i = 1; i < (N - 1); ++i) {
		if (isDisturbed(i)) {
			m[i - 1] += 1;
			m[i + 1] += 1;
			++ans;
		}
	}

	if (ans > 0) {
		t = 0;

		for (i = 1; i < (N - 1); ++i) {
			if (isDisturbed(i)) {
				++t;

				if (m[i - 1] > m[i + 1]) {
					A[i - 1] = 0;
				} else {
					A[i + 1] = 0;
				}
			}

			if (isSolution()) {
				break;
			}
		}

		ans = min(ans, t);
	}

	cout << ans << '\n';
	return 0;
}
