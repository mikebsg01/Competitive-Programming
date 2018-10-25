#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
#define MAXN 200005
#define PB push_back
using namespace std;
typedef long long int lli;

lli N, T;
vector<int> A;

int main() {
	int i, a, counter;
	lli Sum = 0, V, M, C = 0, t;
	bool proceed;

	cin >> N >> T;

	for (i = 0; i < N; ++i) {
		cin >> a;
		A.PB(a);
		
		Sum += a;
	}

	do {
		N = A.size();
		Sum = counter = 0;
		t = T;

		for (i = 0; i < N; ++i) {
			if (A[i] <= t) {
				Sum += A[i];
				t -= A[i];
				++counter;
			}
		}

		if (Sum > 0) {
			V = T / Sum;
			M = Sum * V;
			T -= M;
			C += (V * counter);
		}

	} while (T > 0 and counter > 0);	

	cout << C << endl;
	return 0;
}
