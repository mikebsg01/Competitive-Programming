#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for (int i = a; i > b; --i)
#define CFOR(i,a,b,c) for (int i = a; i != b; i += c)
#define PB(s,x) s.push_back(x)
#define MP make_pair
#define X first
#define Y second
#define SZ size()
using namespace std;
typedef pair<int, int> Pair;

int N, M;
vector<int> A;

int main() {
	optimize_io
	int x, a, b, current, ans;
	cin >> N;

	FOR(i, 0, N) {
		cin >> x;
		PB(A, x);
	}

	cin >> M;

	FOR(i, 0, M) {
		cin >> a >> b;
		--a; --b;
		current = ans = A[a];

		FOR(j, a + 1, b + 1) {
			current = max(A[j], current + A[j]);
			ans = max(ans, current);
		}

		cout << ans << '\n';
	}
	return 0;
}
