#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int M;

inline bool isPrime(int n) {
	if (n == 2) return true;
	else if (n % 2 == 0) return false;

	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	optimize_ios
	int i, j, n, sum;
	string s;
	cin >> M;

	for (i = 0; i < M; ++i) {
		cin >> s;
		n = s.size(), sum = 0;

		for (j = 0; j < n; ++j) {
			sum += s[j] - '0';
		}

		cout << (isPrime(sum) ? "" : "No ") << "UltraPrimo" << '\n';
	}
	return 0;
}
