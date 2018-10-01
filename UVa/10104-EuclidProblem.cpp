#include <iostream>
#include <algorithm>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int gcdExtended(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x2, y2, gcd, q = a / b;

	gcd = gcdExtended(b, a % b, x2, y2);

	x = y2;
	y = x2 + (y2 * -q);

	return gcd;
}

inline int absSum(int x, int y) {
	return abs(x) + abs(y);
}

int main() {
	optimize_ios

	int A, B, X, Y, D, x0, y0, yn, xn, n, absSumXY;

	while (cin >> A >> B) {
		D = gcdExtended(A, B, X, Y);
		
		if (X > Y) {
			yn = x0 = X; yn = y0 = Y; n = 0;
			absSumXY = absSum(X, Y);
			
			while (xn > yn and absSum(xn, yn) <= absSumXY) {
				++n;
				xn = x0 - (B/D) * n;
				yn = y0 + (A/D) * n;
			}

			if (xn <= yn and absSum(xn, yn) <= absSumXY) {
				swap(X, xn);
				swap(Y, yn);
			}
		}

		cout << X << ' ' << Y << ' ' << D << '\n';
	}
	return 0;
}
