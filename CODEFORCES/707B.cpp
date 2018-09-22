#include <bits/stdc++.h>
#define MAXN 100002
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define INF -1
using namespace std;
typedef pair<int, int> P;

int N, M, K;
vector<P> E[MAXN];
vector<int> S;
bool isStorage[MAXN];
int ans = -1;

int main() {
	int i, j, u, v, l, n;

	cin >> N >> M >> K;

	for (i = 0; i < M; ++i) {
		cin >> u >> v >> l;
		E[u].PB(MP(v, l));
		E[v].PB(MP(u, l));
	}

	for (i = 0; i < K; ++i) {
		cin >> u;

		S.PB(u);
		isStorage[u] = true;
	}

	for (i = 0; i < K; ++i) {
		n = E[S[i]].size();

		for (j = 0; j < n; ++j) {
			if (!isStorage[E[S[i]][j].X]) {
				if (ans == INF) {
					ans = E[S[i]][j].Y;
					continue;
				}

				ans = min(ans, E[S[i]][j].Y);
			}
		}
	}

	cout << ans << "\n";
	return 0;
}
