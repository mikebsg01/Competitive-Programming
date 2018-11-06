#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define MAXN 1005
#define EPS 1e-7
#define PRECISION 7
#define DECIMAL_DIGITS 10
using namespace std;

int S, N, I;
double P, Q, sum;

int main() {
	optimize_io
	int i;
	double xi, t;
	cin >> S;

	while(S--) {
		cin >> N >> P >> I;
		Q = 1 - P;
		xi = I - 1;
		sum = 0;
		for (i = 0; i < PRECISION * DECIMAL_DIGITS + 1; ++i) {
			t = P * pow(Q, (i * N) + xi);
			sum += t;
		}
		cout << fixed << setprecision(4) << sum << '\n';
	}
	return 0;
}
