#include <bits/stdc++.h>
#define MAXN 25
using namespace std;
typedef long long int lli;

int N;
int P[MAXN], p;
lli ans;

void backtrack(int level) {
	if (level == N) {
		++ans;
		for (int i = 0; i < level; ++i) {
			cout << P[i] << ' ';
		}
		cout << endl;
		return;
	}

	if (level == 0 or P[level - 1] != 0) {
		P[level] = 0;
		backtrack(level + 1);
	}

	P[level] = 1;
	backtrack(level + 1);
}

int main() {
	cin >> N;
	backtrack(0);
	cout << ans << endl;
	return 0;
}
