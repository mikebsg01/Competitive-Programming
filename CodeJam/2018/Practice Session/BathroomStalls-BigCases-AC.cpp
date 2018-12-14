#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
#define X first
#define Y second
using namespace std;
typedef unsigned long long int ulli;
typedef pair<ulli, ulli> P;

ulli N, K;

inline bool esImpar(ulli num) {
	return num % 2;
}

P calc() {
	ulli n = N, pot = 2, par = 0, impar = 0, t, limit, finalVal;
	P p;

	if (esImpar(n)) {
		impar = 1;
	} else {
		par = 1;
	}
	
	while (K >= pot) {
		t = impar * 2;
		impar = par;

		if (n == 3 or n == 4) {
			impar += t;
		} else if ((esImpar(n) and esImpar(n / 2)) or (esImpar(n - 1) and esImpar((n - 1) / 2))) {
			impar += t;
		} else {
			par += t;
		}

		//dd(par);
		//dd(impar);
		n /= 2;
		pot *= 2;
	}

	//dd(pot);
	//dd(n);
	pot /= 2;
	limit = esImpar(n) ? (pot + impar) : (pot + par);
	finalVal = K < limit ? n : (n - 1);
	// dd(finalVal);
	p.X = (finalVal - 1) / 2; p.Y = (finalVal - 1) - p.X;
	return p;
}

int main() {
	int T;
	P p;
	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cin >> N >> K;
		p = calc();
		cout << "Case #" << i << ": " << p.Y << " " << p.X << "\n";
	}
	return 0;
}
