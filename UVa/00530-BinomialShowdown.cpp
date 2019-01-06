#include <iostream>
#include <algorithm>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define PB(s,x) s.push_back(x)
#define SZ size()
using namespace std;
typedef long long int lli;

lli pascal(lli n, lli k) {
	lli ans = 1;
	k = min(k, n - k);

	FOR(i, 1, k + 1) {
		ans = ans * (n - i + 1) / i;
	}

	return ans;
}

int main() {
	optimize_io
	lli N, K;
	while (cin >> N >> K, N != 0 or K != 0) {
		cout << pascal(N, K) << '\n';
	}
	return 0;
}
