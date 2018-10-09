#include <bits/stdc++.h>
#define EB emplace_back
#define MOD 987654321
using namespace std;
typedef unsigned long long int ulli;

int N;
vector<bool> isPrime;
vector<int> primes;

void criba() {
	int i, j;

	isPrime.assign(N + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (i = 4; i <= N; i += 2) {
		isPrime[i] = false;
	}

	for (i = 3; i * i <= N; ++i) {
		if (isPrime[i]) {
			for (j = 2; i * j <= N; ++j) {
				isPrime[i * j] = false;
			}
		}
	}

	if (N >= 2) {
		primes.EB(2);
	}

	for (i = 3; i <= N; i += 2) {
		if (isPrime[i]) {
			primes.EB(i);
		}
	}
}

inline ulli modSum(ulli a, ulli b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}

inline ulli modMult(ulli a, ulli b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}

int legendre(int n, int p) {
	int exp = 0;

	while (n > 0) {
		n /= p;
		exp += n;
	}

	return exp;
}

int getNumberOfDivisors(int n) {
	if (n <= 1) {
		return n;
	}

	criba();

	int i, j, exp, s = primes.size();
	ulli ans = 1;
	
	for (i = 0; i < s; ++i) {
		exp = legendre(n, primes[i]);
		ans = modMult(ans, exp + 1);
	}

	return ans;
}

int main() {
	cin >> N;
	cout << getNumberOfDivisors(N) << '\n';
	return 0;
}
