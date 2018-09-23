#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 102
#define PB push_back
using namespace std;

int T, N;
vector<int> E[MAXN];
bool before[MAXN];
bool after[MAXN];

void printArray(bool array[]) {
	int i;

	cout << "Array:\n";
	for (i = 0; i < N; ++i) {
		cout << array[i] << " ";
	}
	cout << "\n";
}

void DFSWithAllNodes(int node) {
	if (before[node]) {
		return;
	}

	int n, i;

	before[node] = true;
	n = E[node].size();

	for (i = 0; i < n; ++i) {
		DFSWithAllNodes(E[node][i]);
	}
}

void DFSAfterRemoveNode(int nodeSrc, int nodeX) {
	if (nodeSrc == nodeX or after[nodeSrc]) {
		return;
	}

	int n, i;

	after[nodeSrc] = true;
	n = E[nodeSrc].size();

	for (i = 0; i < n; ++i) {
		DFSAfterRemoveNode(E[nodeSrc][i], nodeX);
	}
}

void printDominators(int c) {
	DFSWithAllNodes(0);

	int i, j;

	cout << "Case " << c << ":\n+";

	for (i = 0; i < (2 * N - 1); ++i) {
		cout << '-';
	}

	cout << "+\n";

	for (i = 0; i < N; ++i) {
		DFSAfterRemoveNode(0, i);

		cout << '|';
		for (j = 0; j < N; ++j) {
			cout << ((before[j] ^ after[j]) ? 'Y' : 'N') << '|';
		}

		cout << "\n+";

		for (j = 0; j < (2 * N - 1); ++j) {
			cout << '-';
		}

		cout << "+\n";

		memset(after, 0, sizeof(after));
	}
	
	memset(before, 0, sizeof(before));
}

int main() {
	optimize_ios

	int i, j, k, c;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		cin >> N;

		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				cin >> c;

				if (c == 1) {
					E[j].PB(k);
				}
			}
		}
		
		printDominators(i);

		for (j = 0; j < N; ++j) {
			E[j].clear();
		}
	}
	return 0;
}
