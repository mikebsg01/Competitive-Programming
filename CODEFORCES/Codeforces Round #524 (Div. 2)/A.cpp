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

double N, K;

ulli f(double n, double k) {
	ulli a = (ulli) ceil((2.0 * n) / k);
	ulli b = (ulli) ceil((5.0 * n) / k);
	ulli c = (ulli) ceil((8.0 * n) / k);
	return a + b + c;
}

int main() {
	optimize_io
	cin >> N >> K;
	cout << f(N, K) << '\n';
	return 0;
}
