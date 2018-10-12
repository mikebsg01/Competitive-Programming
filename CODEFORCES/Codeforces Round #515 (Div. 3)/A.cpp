#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int T, L, V, l, r, ans;

int main() {
	int div, dif;

	optimize_ios

	cin >> T;

	while(T--) {
		cin >> L >> V >> l >> r;
		
		ans = L / V;
		div = l / V;
		ans = (l % V == 0) ? (ans - 1) : ans;
		l = div * V;
		dif = r - l;
		ans -= (dif/V);

		cout << ans << '\n';
	}
	return 0;
}
