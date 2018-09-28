#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 10002
#define PB push_back
#define dd(x) cout << #x << " " << x << "\n";
using namespace std;
typedef unsigned long long int ulli;
#define MOD ((ulli) (1e9 + 7))
typedef vector<ulli> V;
typedef set<V> S;

int N;
V P; int p;
S s;
int sets;

void printVector(V &v) {
	int n = v.size();

	cout << "\nVector:\n";

	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}

	cout << "\n\n";
}

void printSet() {
	V t;

	for (S::iterator it = s.begin(); it != s.end(); ++it) {
        	t = (*it);

                printVector(t);
	}
}

ulli countingSums(int n) {
	if (n == 0) {
		V t(P);
		s.insert(t);
		++sets;
		return 1;
	}

	int i;
	ulli ans = 0;
	
	for (i = n; i >= 1; --i) {
		P[i - 1]++;
		ans += countingSums(n - i) % MOD;
		ans += MOD;
		--P[i - 1];
	}

	return ans % MOD;
}

int main() {
	optimize_ios

	while (cin >> N) {
		sets = 0;
		P.resize(N, 0);
		s.clear();
		countingSums(N);
		cout << (s.size() % MOD) << "\n";
		dd(sets);
	}
	return 0;
}
