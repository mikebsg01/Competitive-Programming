#include <iostream>
#include <vector>
#include <algorithm>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define MAXN 10005
using namespace std;

int A, C, V[MAXN];

int main() {
	optimize_io
	int i, ans;

	while (cin >> A >> C, A != 0 and C != 0) {
		ans = 0;

		for (i = 0; i < C; ++i) {
			cin >> V[i];

			if (i > 0 and V[i - 1] < V[i]) {
				ans += V[i] - V[i - 1];
			}
		}

		if (V[C - 1] < A) {
			ans += A - V[C - 1];
		}

		cout << ans << '\n';
	}
	return 0;
}
