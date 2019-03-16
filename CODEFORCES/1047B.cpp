#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define PB push_back
#define MP make_pair
#define Y first
#define X second
#define ALL(s) s.begin(), s.end()
using namespace std;
typedef unsigned long long int ulli;
typedef pair<ulli, ulli> Pair;

int N;
ulli ans;

int main() {
	optimize_io
	ulli x, y;
	cin >> N;

	FOR(i, 0, N) {
		cin >> x >> y;
		ans = max(ans, x + y);
	}

	cout << ans << '\n';
	return 0;
}
