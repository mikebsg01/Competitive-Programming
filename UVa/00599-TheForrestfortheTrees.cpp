#include <bits/stdc++.h>
#define MAXN 28
#define PB push_back
using namespace std;

int T;
vector<int> E[MAXN];
vector<int> V;
bool vis[MAXN];

inline int idx(char c) {
	return ((int) (c-'A'));
}

int bfs(int start) {
	if (vis[start]) {
		return 0;
	}

	int n, i, a, ans = 0;
	queue<int> Q;

	vis[start] = true;
	Q.push(start);

	while (!Q.empty()) {
		a = Q.front();
		Q.pop();
		++ans;

		n = E[a].size();
		
		for (i = 0; i < n; ++i) {
			if (!vis[E[a][i]]) {
				vis[E[a][i]] = true;
				Q.push(E[a][i]);
			}
		}
	}

	return ans;
}

int main() {
	int n, i, nodes, trees, acorns;
	char x, y;
	string s;

	cin >> T;

	while (T--) {
		trees = acorns = 0;

		while (cin >> s) {
			if (s[0] == '*') {
				break;
			}

			x = s[1];
			y = s[3];

			E[idx(x)].PB(idx(y));
			E[idx(y)].PB(idx(x));
		}

		cin >> s;
		n = s.size();

		for (i = 0; i < n; ++i) {
			if (s[i] == ',') {
				continue;
			}

			V.PB(idx(s[i]));
		}

		n = V.size();

		for (i = 0; i < n; ++i) {
			nodes = bfs(V[i]);

			if (nodes > 1) {
				++trees;
			} else if (nodes == 1) {
				++acorns;
			}
		}

		cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
		
		memset(vis, 0, sizeof(vis));

		for (i = 0; i < n; ++i) {
			E[V[i]].clear();
		}

		V.clear();
	}
	return 0;
}
