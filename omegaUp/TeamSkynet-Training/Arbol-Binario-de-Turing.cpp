#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 1000002
#define MOD 21092013
#define INF -1
using namespace std;
typedef stack<bool> stackbl;
typedef stack<int> stacki;

string S, T;
stackbl Tree;
stacki MovsLater;
bool direction;
int DP[MAXN];
int lastOccurrence[3];

inline int getIdx(char c) {
	return c == 'L' ? 0 : (c == 'R' ? 1 : 2);
}

inline char toChar(bool idx) {
	return idx ? 'R' : 'L';
}

inline bool isMovDown(char c) {
	return c == 'L' or c == 'R';
}

bool dontHaveMovUp() {
	int i, n = T.size();
	bool res = true;

	for (i = 0; i < n; ++i) {
		if (!isMovDown(T[i])) {
			res = false;
		} else {
			direction = getIdx(T[i]);

			if (! res) {
				return res;
				break;
			}
		}
	}

	return res;
}

inline int modMult(int a, int b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}

inline int modPositive(int n) {
	return ((n % MOD) + MOD) % MOD;
}

inline int modSub(int a, int b) {
	return ((a % MOD) - (b % MOD)) % MOD;
}

inline int modSum(int a, int b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}

int countDistinctSubsequences() {
	int i, n, charIdx;

	n = T.size(), DP[0] = 1;

	for (i = 1; i <= n; ++i) {
		DP[i] = modMult(2, DP[i - 1]);
		charIdx = getIdx(T[i - 1]); 

		if (lastOccurrence[charIdx] > 0) {
			DP[i] = modPositive(modSub(DP[i], DP[lastOccurrence[charIdx] - 1]));
		}

		lastOccurrence[charIdx] = i;
	}

	return DP[n];
}

void getTree() {
	int i, n = S.size();

	for (i = 0; i < n; ++i) {
		if (isMovDown(S[i])) {
			Tree.push(getIdx(S[i]) ^ 1);
		} else if (! Tree.empty()) {
			Tree.pop();
		}
	}
}

void findMovsLater() {
	int i, n = T.size(), movs = 0;

	for (i = n - 1; i >= 0; --i) {
		if (isMovDown(T[i])) {
			++movs;
		} else {
			MovsLater.push(movs);
		}
	}

	MovsLater.push(movs);
}

int countDistinctNodes() {
	int movs, res = 0, i = 0, parentDirection;

	while ((! MovsLater.empty()) and (! Tree.empty())) {
		movs = MovsLater.top();
		MovsLater.pop();

		if (i == 0) {
			res = modSum(res, modSum(movs, 1));
		} else {
			parentDirection = Tree.top();
			Tree.pop();

			if (parentDirection == direction) {
				res = modSum(res, movs);
			}

			res = modSum(res, 1);
		}

		++i;
	}

	return res;
}

int main() {
	optimize_ios

	cin >> S >> T;

	getTree();

	if (dontHaveMovUp()) {
		cout << countDistinctSubsequences() << '\n';
	} else {
		findMovsLater();
		cout << countDistinctNodes() << '\n';
	}
	return 0;
}
