#include <bits/stdc++.h>
#define MAXN 6
using namespace std;

int A, B;

int main() {
	int X, Y, g;
	cin >> A >> B;
	Y = MAXN;
	X = Y - (max(A, B) - 1);
	g = __gcd(X, Y);
	X /= g;
	Y /= g;
	cout << X << '/' << Y << '\n';
	return 0;
}
