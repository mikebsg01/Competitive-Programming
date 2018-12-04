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
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef vector<bool> vectorbl;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef map<int, int> mapi;

lli N;
vectorlli A;

void printArray() {
	cout << endl;
	for (int i = 0; i < N; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;
}

bool isSolution() {
	int n = A.size();

	if (n == 1) {
		return true;
	}

	for (int i = 1; i < n; ++i) {
		if (A[i - 1] >= A[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	optimize_io
	int i, j;
	lli x, sum, mod;
	vector<Tern> ans;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> x;
		PB(A, x);
	}

	if (isSolution()) {
		cout << "0\n";
	} else {
		printArray();

		sum = 7;
		PB(ans, MP(1, MP(N - 1, sum)));

		for (i = 0; i < N; ++i) {
			A[i] += sum;
		}

		printArray();

		for (i = N - 1; i >= 0; --i) {
			if (A[i] < i) {
				sum = i - A[i];
				
				for (j = 0; j <= i; ++j) {
					A[j] += sum;
				}

				PB(ans, MP(1, MP(i, sum)));
			} else if (A[i] > i) {
				mod = A[i] - i;

				for (j = 0; j <= i; ++j) {
					A[j] %= mod;
				}
				PB(ans, MP(2, MP(i, mod)));
			}

			printArray();
		}

		int M = ans.size();
		cout << M << endl;

		for (i = 0; i < M; ++i) {
			cout << ans[i].X << " " << (ans[i].Y.X + 1) << " " << ans[i].Y.Y << endl;
		}
	}
	return 0;
}
