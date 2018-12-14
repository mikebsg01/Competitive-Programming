#include <bits/stdc++.h>
#define PB push_back
#define MAXN 2005
#define ver(x) cout << #x << ": " << x << endl
using namespace std;

int T, N, L;
vector<char> A[MAXN];
set<string> S;
char P[MAXN]; int p;
string ans;

void getDiff(int level) {
	if (!ans.empty()) {
		return;
	}

	if (level >= L) {	
		if (S.count(P) == 0) {
			ans = P;
		}
		return;
	}
	int i;

	for (i = 0; i < N; ++i) {
		P[p++] = A[i][level];
		getDiff(level + 1);
		P[--p] = 0;
	}
}

int main() {
	int i, j, k, l;
	string x;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		cin >> N >> L;
		ans.clear();

		for (j = 0; j < N; ++j) {
			cin >> x;

			for (k = 0; k < L; ++k) {
				A[j].PB(x[k]);
			}
			S.insert(x);
		}
		getDiff(0);
		cout << "Case #" << i << ": " << (ans.empty() ? "-" : ans) << "\n";
		
		for (j = 0; j < MAXN; ++j) {
			A[j].clear();
		}
		S.clear();
	}
	return 0;
}
