#include <bits/stdc++.h>
#define PB push_back
#define MAXN 2005
#define MAXL 15
#define ver(x) cout << #x << ": " << x << endl
using namespace std;

int T, N, L;
set<string> S;
vector<char> A[MAXN];
map<char, int> getIndex[MAXL];
map<int, char> getChar[MAXL];
string ans;

void order() {
	int i, j;
	set<char> tmp;
	set<char>::iterator it;

	for (j = 0; j < L; ++j) {
		for (i = 0; i < N; ++i) {
			tmp.insert(A[i][j]);
		}
		
		for (it = tmp.begin(), i = 0; it != tmp.end(); ++it, ++i) {
			getIndex[j][*it] = i;
			getChar[j][i] = *it;
		}
		tmp.clear();
	}
}

void getDiff() {
	int i, j, k, l, idx;
	char c;
	string tmp;
	set<string>::iterator it;

	for (it = S.begin(), i = 0; it != S.end(); ++it, ++i) {
		tmp = *it;

		for (j = 0; j < L; ++j) {
			c = tmp[j];
			idx = getIndex[j][c];	


			for (k = 0, l = 1; k < 2; ++k, l *= -1) {
				if (getChar[j].count(idx + l) > 0) {
					tmp[j] = getChar[j][idx + l];

					if (S.count(tmp) == 0) {
						ans = tmp;
						return;
						break;
					}
	
					tmp[j] = c;
				}
			}
		}
	}
}

int main() {
	int i, j, k, l;
	string x;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		cin >> N >> L;

		for (j = 0; j < N; ++j) {
			cin >> x;

			for (k = 0; k < L; ++k) {
				A[j].PB(x[k]);
			}

			S.insert(x);
		}
	
		order();
		getDiff();
		cout << "Case #" << i << ": " << (ans.empty() ? "-" : ans) << "\n";
		
		for (j = 0; j < MAXN; ++j) {
			A[j].clear();
		}
		S.clear();
		
		for (j = 0; j < MAXL; ++j) {
			getIndex[j].clear();
			getChar[j].clear();
		}	
		ans.clear();
	}
	return 0;
}
