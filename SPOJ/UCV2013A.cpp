#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define MOD (((int)1e9) + 7)
using namespace std;
typedef long long int lli;

lli N, L, ans;

lli mod(lli n) {
	return ((n % MOD) + MOD) % MOD;
}

lli modSum(lli a, lli b) {
	return mod(mod(a) + mod(b));
}

lli modMult(lli a, lli b) {
	return mod(mod(a) * mod(b));
}

lli exp(lli n, lli p) {
	if (p == 0) {
		return 1;
	}

	lli a = mod(exp(n, p / 2)), b = 1;

	if ((p % 2) != 0) {
		b = n;
	}

	return modMult(modMult(a, a), b);
}

int main() {
	optimize_io

	while (cin >> N >> L, N != 0 or L != 0) {
		ans = 0;

		FOR(i, 1, L + 1) {
			ans = modSum(ans, exp(N, i));
		}

		cout << ans << '\n';
	}
	return 0;
}
