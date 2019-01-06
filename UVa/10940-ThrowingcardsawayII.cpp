#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define RFOR(i,a,b) for (int i = (a); i > (b); --i)
#define PUSHF(s,x) s.push_front(x)
#define PUSHB(s,x) s.push_back(x)
#define POPF(s) s.pop_front()
#define POPB(s) s.pop_back()
#define FRONT(s) s.front()
#define BACK(s) s.back()
#define SZ size()
using namespace std;

int main() {
	optimize_io
	int N, p;
	while (cin >> N, N != 0) {
		p = 1 << ((int) log2(N - 1));
		cout << ((N == 1) ? 1 : (2 * (N - p))) << '\n';	
	}
	return 0;
}
