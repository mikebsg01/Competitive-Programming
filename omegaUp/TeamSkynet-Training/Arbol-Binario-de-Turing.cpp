#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define ALL(x) x.begin(), x.end()
#define L 0
#define R 1
#define INF -1
#define MOD 21092013
using namespace std;
typedef stack<short> stacki;
typedef pair<int, int> Pair;
typedef pair<int, Pair> Tern;

string S, T;
stacki ParentDirections;
vector<int> DP;
int last[3];
int ans;

inline int modPositive(int n) {
	return ((n % MOD) + MOD) % MOD;
}

inline int modSub(int a, int b) {
	return modPositive(((a % MOD) - (b % MOD)) % MOD);
}

inline int modSum(int a, int b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}

inline int modMult(int a, int b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}

inline short getIdx(char c) {
	return (c == 'L' ? 0 : ((c == 'R') ? 1 : 2));
}

inline bool isUp(char c) {
	return c == 'U';
}

void getFinalDirections() {
	int i, n = S.size();

	for (i = 0; i < n; ++i) {
		if (! isUp(S[i])) {
			ParentDirections.push(getIdx(S[i]) ^ 1);
		} else if (! ParentDirections.empty()) {
			ParentDirections.pop();
		}
	}
}

void calculate() {
	int n, i, j, idx, lastLIdx = INF, lastRIdx = INF, subsequencesCount, dpIdx;
	vector<Tern> uIdx;

	DP.PB(1);

	for (i = T.size() - 1, j = 1; i >= 0; --i) {
		idx = getIdx(T[i]);

		if (! isUp(T[i])) {
			DP.PB(modMult(2, DP[j - 1]));

			if (last[idx] > 0) {
				DP[j] = modSub(DP[j], DP[last[idx] - 1]);
			}

			if (idx == L) {
				lastLIdx = j;
			} else {
				lastRIdx = j;
			}

			last[idx] = j++;
		} else {
			uIdx.PB(MP(j - 1, MP(lastLIdx, lastRIdx)));
		}
	}

	ans = modSum(ans, DP[j - 1]);

	for (i = uIdx.size() - 1; i >= 0 and ! ParentDirections.empty(); --i) {
		idx = ParentDirections.top(); ParentDirections.pop();
		subsequencesCount = DP[uIdx[i].X];
		dpIdx = idx == R ? uIdx[i].Y.X : uIdx[i].Y.Y;

		if (dpIdx == INF) {
			ans = modSum(ans, subsequencesCount);
		} else {
			ans = modSum(ans, modSub(subsequencesCount, DP[dpIdx - 1]));
		}
	}
}

int main() {
	optimize_ios

	cin >> S >> T;

	getFinalDirections();
	calculate();

	cout << ans << '\n';
	return 0;
}
