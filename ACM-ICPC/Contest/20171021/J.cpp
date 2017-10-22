#include <bits/stdc++.h>
#define MAXN 32
using namespace std;

int N;
vector<int> A[MAXN];
int vis[MAXN];

int toInt(char c) {
	return ((char)(c-'A'));
}

void bfs(int init) {
	int a, i, ans = 0;
	queue<int> Q;
	Q.push(init);
	vis[init] = 1;
	
	while (!Q.empty()) {
		a = Q.front();
		Q.pop();
		
		for (i = 0; i < A[a].size(); ++i) {
			if (!vis[A[a][i]]) {
				vis[A[a][i]] = 1;
				Q.push(A[a][i]);
			}	
		}
	}
}

int main() {
	int i, ans;
	char c, x, y;
	string s;

	while (getline(cin, s)) {
		c = s[0];
		N = toInt(c) + 1;
		ans = 0;

		for (i = 0; i < N; ++i) {
			A[i].push_back(i);
		}
	
		while (getline(cin, s)) {
			if (s.size() != 2) {
				break;
			}

			x = toInt(s[0]);
			y = toInt(s[1]);
			A[x].push_back(y);
			A[y].push_back(x);
		}

		for (i = 0; i < N; ++i) {
			if (!vis[i]) {
				bfs(i);
				++ans;
			}
		}

		cout << ans << "\n";
		memset(vis, 0, sizeof(vis));
		
		for (i = 0; i < MAXN; ++i) {
			A[i].clear();
		}
	}
	return 0;
}
