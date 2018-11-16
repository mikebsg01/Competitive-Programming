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
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;
typedef map<int, int> mapi;

int N;
lli A, B, K;

inline lli f(lli x, lli y) {
	return (x * A) - (y * B);
}

int main() {
	optimize_io
	int i;
	lli x, y;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> A >> B >> K;
		y = ((lli) (K / 2));
		x = K - y;
		cout << f(x, y) << '\n';
	}
	return 0;
}
