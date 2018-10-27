#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define ALL(s) s.begin(), s.end()
#define PB(s, x) s.push_back(x)
#define IN(s, x) s.insert(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define END(s, it) it == s.end()
#define BEGIN(s, it) it == s.begin()
#define MP make_pair
#define X first
#define Y second
using namespace std;
typedef long long int lli;
typedef pair<int, int> pairii;
typedef set<int> seti;

int N;
vector<pairii> A;
seti indexes;
lli ans;

inline int countLeftNums(int currentIdx, int leftIdx) {
	return currentIdx - leftIdx;
}

inline int countRightNums(int currentIdx, int rightIdx) {
	return rightIdx - currentIdx;
}

lli countContainerIntervals(int currentIdx, int leftIdx, int rightIdx) {
	lli	L = countLeftNums(currentIdx, leftIdx),
		R = countRightNums(currentIdx, rightIdx);

	return (L + 1) * (R + 1);
}

int main() {
	optimize_ios
	int i, x, currentIdx, leftIdx, rightIdx;
	lli intervals;
	seti::iterator tmp, leftLimit, rightLimit;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> x;
		PB(A, MP(x, i));
	}

	sort(ALL(A));
	IN(indexes, -1);
	IN(indexes, N);

	for (i = 0; i < N; ++i) {
		currentIdx = A[i].Y;
		IN(indexes, currentIdx);
		tmp = LOWER(indexes, currentIdx);
		leftLimit = seti::iterator(tmp);
		--leftLimit;
		rightLimit = seti::iterator(tmp);
		++rightLimit;

		rightIdx = (*rightLimit) - 1;
		leftIdx = (*leftLimit) + 1;

		intervals = countContainerIntervals(currentIdx, leftIdx, rightIdx);
		ans += (intervals * A[i].X);
	}
	cout << ans << '\n';
	return 0;
}
