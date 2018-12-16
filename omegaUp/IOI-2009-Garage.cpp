#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define PB(s, v) s.push_back(v)
#define UNDEFINED -1
using namespace std;
typedef vector<int> vectori;
typedef vector<bool> vectorbl;

int N, M;
vectori R, W, place;
vectorbl vis; int counter;
queue<int> Q;
int ans;

void park() {
	int idx, i;

	while (!Q.empty() and counter < N) {
		idx = Q.front();
		Q.pop();

		for (i = 0; i < N; ++i) {
			if (! vis[i]) {
				vis[i] = true;
				place[idx] = i;
				ans += R[i] * W[idx];
				++counter;
				break;
			}
		}
	}
}

int main() {
	optimize_io
	int i, x;
	cin >> N >> M;
	vis.assign(N, false);
	place.assign(M, UNDEFINED);

	for (i = 0; i < N; ++i) {
		cin >> x;
		PB(R, x);
	}

	for (i = 0; i < M; ++i) {
		cin >> x;
		PB(W, x);
	}

	for (i = 0; i < 2 * M; ++i) {
		cin >> x;

		if (x > 0) {
			Q.push(x - 1);
		} else {
			x = abs(x) - 1;
			vis[place[x]] = false;
			place[x] = UNDEFINED;
			--counter;
		}

		park();
	}

	cout << ans << '\n';
	return 0;
}
