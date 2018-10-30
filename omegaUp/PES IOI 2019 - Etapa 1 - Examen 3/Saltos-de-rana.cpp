#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define ALL(s) s.begin(), s.end()
#define INF -1
using namespace std;
typedef vector<int> vectori;

int N, K;
string S;
vectori A;

int getUpperBound(int val) {
	vectori::iterator up = upper_bound(ALL(A), val);

	return ((int) (up - A.begin()));
}

inline bool isPossible(int a, int b) {
	return (a != b) and ((b - a) <= K);
}

int getMinimumJumps(int startPos) {
	int currentPos = startPos, endPos = N - 1, nextPosIdx, nextPos, jumps = 0;

	while (currentPos < endPos) {
		nextPosIdx = getUpperBound(currentPos + K) - 1;
		nextPos = A[nextPosIdx];
	
		if (!isPossible(currentPos, nextPos)) {
			return INF;
		}

		currentPos = nextPos;
		++jumps;
	}
	return jumps;
}

int main() {
	optimize_ios
	int i;
	cin >> N >> K;
	cin >> S;

	for (i = 0; i < N; ++i) {
		if (S[i] == '1') {
			PB(A, i);
		}
	}

	for (i = 0; i < K; ++i) {
		PB(A, N + i);
	}

	cout << getMinimumJumps(0) << endl;
	return 0;
}
