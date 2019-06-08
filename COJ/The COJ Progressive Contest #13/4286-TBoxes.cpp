#include <bits/stdc++.h>
#define FOR(t,i,a,b) for(t i = a; i != b; ++i)
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef unsigned long long int ulli;

int N;

int main() {
	optimize_io
	ulli a, b, x;
	cin >> N >> x;
	a = b = x;
	cout << (2 * x)  << '\n';

	FOR(int, i, 1, N) {
		cin >> x;
		a = min(a, x);
		b = max(b, x);
		cout << (a + b) << '\n';
	}
	return 0;
}
