#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef vector<bool> vectorbl;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef map<int, int> mapi;

lli T, N;

int main() {
	optimize_io
	lli div, mult, a, b;
	bool solution = false;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i % j == 0) {
				div = i / j;
				mult = i * j;
			
				if (mult > N and div < N) {
					a = i;
					b = j;
					solution = true;
					break;
				}
			}
		}

		if (solution) {
			break;
		}
	}
	if (solution) {
		cout << a << ' ' << b << '\n'; 
	} else {
		cout << "-1\n";
	}
	return 0;
}
