#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 102
#define PB push_back
#define dd(x) cout << #x << ": " << x << "\n";
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef set<int> SI;
typedef vector<SI> VSI;

int T, N;
VI E[MAXN];
VSI P[MAXN];
bool vis[MAXN];

void printVector(SI &s) {
	int i;

	for (SI::iterator it = s.begin(); it != s.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << "\n";
}

void printAllPathsFromStartNode() {
	int i, j, m;

	for (i = 0; i < N; ++i) {
		cout << "Node: " << i << ":\n";

		m = P[i].size();

                for (j = 0; j < m; ++j) {

                        for (SI::iterator it = P[i][j].begin(); it != P[i][j].end(); ++it) {
                        	cout << (*it) << " ";
                       	}
                        cout << "\n";
              	}
               	cout << "\n";
	}
}

void bfs(int start) {
	int i, j, n, m, current, adjacent;
	queue<int> Q;
	SI tmp;

	Q.push(start);
	vis[start] = true;
	tmp.insert(start);
	P[start].PB(tmp);

	while (!Q.empty()) {
		current = Q.front();
		Q.pop();

		//dd(current);

		n = E[current].size();
		
		for (i = 0; i < n; ++i) {
			adjacent = E[current][i];

			//dd(adjacent);
			m = P[current].size();

			for (j = 0; j < m; ++j) {
				tmp = P[current][j];

				tmp.insert(adjacent);

				//printVector(tmp);

				P[adjacent].PB(tmp);
				tmp.clear();

				if (!vis[adjacent]) {
					vis[adjacent] = true;
					Q.push(adjacent);
				}
			}
		}
	}

	tmp.clear();
}

bool isDominator(int X, int Y) {
	int i, n;

	n = P[Y].size();

	for (i = 0; i < n; ++i) {
		if (! P[Y][i].count(X)) {
			return false;
		}
	}

	return n > 0;
}

void generateDominatorRelationships() {
	int i, j, k, m;

	cout << '+';

	for (i = 0; i < (2 * N - 1); ++i) {
		cout << '-';
	}

	cout << "+\n";

	for (i = 0; i < N; ++i) {
		cout << '|';
	
		for (j = 0; j < N; ++j) {
			cout << (isDominator(i, j) ? 'Y' : 'N') << '|';
		}

		cout << "\n+";

		for (j = 0; j < (2 * N - 1); ++j) {
			cout << '-';
		}

		cout << "+\n";
	}
}

int main() {
	optimize_ios

	int t, i, j, c;

	cin >> T;
	
	for (t = 1; t <= T; ++t) {
		cin >> N;

		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				cin >> c;

				if (c == 1) {
					E[i].PB(j);
				}
			}
		}

		bfs(0);
		//printAllPathsFromStartNode();
		cout << "Case " << t << ":\n";
		generateDominatorRelationships();

		for (i = 0; i < N; ++i) {
			E[i].clear();
			P[i].clear();
		}

		memset(vis, 0, sizeof(vis));
	}
	return 0;
}
