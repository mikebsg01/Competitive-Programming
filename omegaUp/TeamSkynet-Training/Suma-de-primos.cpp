#include <bits/stdc++.h>
#define PB push_back
#define ALL(x) x.begin(), x.end()
using namespace std;

int N;
vector<bool> isPrime;
vector<int> primes;

void getPrimes() {
	int i;

	primes.PB(2);

	for (i = 3; i <= N; i += 2) {
		if (isPrime[i]) {
			primes.PB(i);
		}
	}
}

void criba() {
	int i, j;

	isPrime.resize(N + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (i = 2; i * 2 <= N; ++i) {
		isPrime[i * 2] = false;
	}

	for (i = 3; i * i <= N; i += 2) {
		if (isPrime[i]) {
			for (j = 2; i * j <= N; ++j) {
				isPrime[i * j] = false;
			}
		}
	}

	getPrimes();
}

int main() {	
	int i, m, sz, diff, a, b;
	bool solution;

	cin >> N;

	criba();

	if (isPrime[N]) {
		cout << N << " 0\n";
	} else if (N < 2 or N & 1) {
		cout << "0 0\n";
	} else {
		m = N / 2;

		for (i = 0; primes[i] <= m; ++i) {
			diff = N - primes[i];

			if (isPrime[diff]) {
				cout << diff << ' ' << primes[i] << '\n';
				return 0;
			}
		}
		
		cout << "0 0\n";
	}
	return 0;
}
