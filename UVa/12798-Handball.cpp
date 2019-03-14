#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i,a,b) for (int i = a; i < b; ++i)
using namespace std;

short N, M, ans;

int main() {
	short x;
	bool allMatches;

	while (cin >> N >> M) {
		ans = 0;

		FOR(i, 0, N) {
			allMatches = true;

			FOR (j, 0, M) {
				cin >> x;

				if (x == 0) {
					allMatches = false;
				}
			}

			if (allMatches) {
				++ans;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
