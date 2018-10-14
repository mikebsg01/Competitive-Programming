#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 200
using namespace std;

int A, B, C;
int ans = MAXN * MAXN * MAXN;

inline int isSolution(int a, int b, int c) {
	return ((a + b) > c) and ((a + c) > b) and ((b + c) > a);
}

int main() {
	optimize_ios

	int i, j, k, s;

	cin >> A >> B >> C;
	s = A + B + C;

	for (i = MAXN; i >= A; --i) {
		for (j = MAXN; j >= B; --j) {
			for (k = MAXN; k >= C; --k) {
				if (isSolution(i, j, k)) {
					ans = min(ans, (i + j + k) - s);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
