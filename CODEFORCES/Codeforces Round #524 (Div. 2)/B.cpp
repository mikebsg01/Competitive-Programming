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

int Q;
lli L, R;

lli getSum(lli a, lli b) {
	lli	c = a + b,
		dist = b - a + 1,
		quantity = (lli) ceil(((double) dist) / 2.0),
		mult = quantity / 2,
		add = (quantity % 2 != 0) ? (c / 2) : 0,
		sum = (a != b) ? (c * mult) : 0;

	return sum + add;
}

lli f() {
	lli p, q, r, s;
	
	if (L % 2 == 0) {
		p = L;
		r = L + 1;
	} else {
		p = L + 1;
		r = L;
	}

	if (R % 2 == 0) {
		q = R;
		s = R - 1;
	} else {
		q = R - 1;
		s = R;
	}

	lli even = getSum(p, q);
	lli odd = getSum(r, s);
	return even - odd;
}

int main() {
	optimize_io
	int i;
	cin >> Q;
	for (i = 0; i < Q; ++i) {
		cin >> L >> R;
		cout << f() << '\n';
	}
	return 0;
}
