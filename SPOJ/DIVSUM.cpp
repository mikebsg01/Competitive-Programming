#include <iostream>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long int lli;

lli countDivisors(int n) {
	lli p, ans = 1;

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			p = n / i;
			ans += i;

			if (p != i) {
				ans += p;
			}
		}
	}

	return (n == 1) ? 0 : ans;
}

int main() {
	optimize_io
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		cout << countDivisors(N) << '\n';
	}
	return 0;
}
