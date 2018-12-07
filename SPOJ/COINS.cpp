#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
using namespace std;
typedef unsigned long long int ulli;
typedef map<ulli, ulli> mapulli;

ulli N;
mapulli memo;


ulli dp(ulli n) {
	if (n == 0 or n == 1) {
		return n;
	}

	if (memo.count(n) > 0) {
		return memo[n];
	}

	ulli ans =  max(n, dp(n / 2) + dp(n / 3) + dp(n / 4));
	
	return memo[n] = ans;
}

int main() {
	optimize_io

	while (cin >> N) {
		cout << dp(N) << '\n';
	}
	return 0;
}
