#include <iostream>
#include <algorithm>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define INF (2 * ((int)1e6) + 117)
using namespace std;

int N;
char C;

int main() {
	optimize_io
	int i, posR, posD, ans;

	while (cin >> N, N != 0) {
		posR = posD = ans = INF;

		for (i = 0; i < N; ++i) {
			cin >> C;

			if (C == 'R') {
				posR = i;
			} else if (C == 'D') {
				posD = i;
			} else if (C == 'Z') {
				posR = posD = i;
				ans = 0;
			}

			if (posR != INF and posD != INF) {
				ans = min(ans, abs(posR - posD));
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
