#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;

lli N, X, Y;

lli manhattanDistance(lli x, lli y) {
	return abs(X - x) + abs(Y - y);
}

lli chebyshevDistance(lli x, lli y) {
	return max(abs(X - x), abs(Y - y));
}

int main() {
	lli a, b;
	cin >> N;
	cin >> X >> Y;
	a = chebyshevDistance(1, 1), b = chebyshevDistance(N, N);
	cout << ((a <= b) ? "White\n" : "Black\n");
	return 0;
}
