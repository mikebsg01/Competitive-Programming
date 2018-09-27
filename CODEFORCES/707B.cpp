#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 100002
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define INF -1
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> T;

int N, M, K;
T E[MAXN];
bool isStorage[MAXN];
int ans = -1;

int main() {
	optimize_ios

	int i, j, u, v, l, n;

	cin >> N >> M >> K;

	for (i = 0; i < M; ++i) {
		cin >> u >> v >> l;
		E[i].X.X = u;
		E[i].X.Y = v;
		E[i].Y = l;
	}

	for (i = 0; i < K; ++i) {
		cin >> u;
		isStorage[u] = true;
	}

	for (i = 0; i < M; ++i) {
		if (isStorage[E[i].X.X] ^ isStorage[E[i].X.Y]) {
				if (ans == INF) {
					ans = E[i].Y;
					continue;
				}

				ans = min(ans, E[i].Y);
		}
	}

	cout << ans << "\n";
	return 0;
}
