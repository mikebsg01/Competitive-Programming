#include <bits/stdc++.h>
#define MAXBITS 32
#define PB(s, x) s.push_back(x)
using namespace std;

int N;
bitset<MAXBITS> bs;
vector<int> A;

int derived(int num) {
	int i, n, ones = 0;

	bs = num;
	string s = bs.to_string();

	for (i = 0, n = s.size(); i < n; ++i) {
		if (s[i] == '1') {
			++ones;
		}
	}

	return ones;
}

int main() {
	int i, j, x, ans = 0;

	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> x;
		x = derived(x);
		PB(A, x);
		cin.ignore();
	}

	N = A.size();

	for (i = 0; i < N; ++i) {
		for (j = i + 1; j < N; ++j) {
			if (A[i] > A[j]) {
				++ans;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
