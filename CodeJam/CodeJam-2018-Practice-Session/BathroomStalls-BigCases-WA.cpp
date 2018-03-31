#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> P;

lli N, K;

bool find(lli l, lli r, lli pot) {
	while (! (l >= K and K >= r) and (l < pot and r < pot)) {
		// cout << "l: " << l << " r: " << r << endl;
		l = 2 * l + 1;
		r = 2 * r;
	}
	// cout << "l: " << l << " r: " << r << endl;
	return l >= K and K >= r;
}

P calc() {
	P p;
	lli n = N - 1;

	if (K == 1) {
		p.X = n / 2; p.Y = n - p.X;
		return p;
	}

	lli potA, potB = 1;

	while (potB <= N) {
		potB *= 2;
	}

	potA = potB / 2;
	--potB;

	if (K >= potA and N < potB) {
		p.X = p.Y = 0;
		return p;
	}

	lli i = 1;
	bool l, r;
	n = N;

	while (i != K) {
		l = find(2 * i + 1, 2 * i + 1, potA);
		r = find(2 * i, 2 * i, potA);
		// cout << ">> l: " << l << " r: " << r << endl;

		if (l) {
			n = (n - 1) / 2;
			i = 2 * i + 1; 
		} else {
			n = (n - 1) - ((n - 1) / 2);
			i = 2 * i;
		}
	}

	p.X = (n - 1) / 2;
	p.Y = (n - 1) - p.X;
	return p;
}

int main() {
	P p;
	int T;
	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cin >> N >> K;
		p = calc();
		cout << "Case #" << i << ": " << p.Y << " " << p.X << "\n";
	}
	return 0;
}
