#include <iostream>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define max(a, b) ((a > b) ? a : b)
#define MAXH 102
#define MAXW 102
using namespace std;

int T, H, W, DP[MAXH][MAXW], MOV_X[] = {-1, 0, 1}, ans;

int main() {
	optimize_io
	int i, j, k, x, greatest;
	cin >> T;

	while (T--) {
		cin >> H >> W;
		ans = 0;

		for (i = 0; i < H; ++i) {
			for (j = 0; j < W; ++j) {
				cin >> DP[i][j];
				greatest = 0;

				if (i > 0) {
					for (k = 0; k < 3; ++k) {
						x = j + MOV_X[k];
						if (x < 0 or x >= W) {
							continue;
						}
						greatest = max(greatest, DP[i - 1][x]);
					}
				}

				DP[i][j] += greatest;
				ans = max(ans, DP[i][j]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
