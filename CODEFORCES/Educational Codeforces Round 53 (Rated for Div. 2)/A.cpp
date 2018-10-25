#include <bits/stdc++.h>
using namespace std;

int N, bucket[28];
string S;
string ans("");

bool isDiverse(string s) {
	memset(bucket, 0, sizeof(bucket));

	int n = s.size(), m = n / 2, i, idx;

	for (i = 0; i < n; ++i) {
		idx = (int) s[i] - 'a';
		++bucket[idx];

		if (bucket[idx] > m) {
			return false;
		}
	}

	return true;
}

int main() {
	int i, j;
	string t;

	cin >> N;
	cin >> S;

	for (i = 1; i <= N; ++i) {
		for (j = 0; j < N - i + 1; ++j) {
			t = S.substr(j, i);

			if (isDiverse(t)) {
				ans = t;
				cout << "YES\n" << ans << '\n';
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}
