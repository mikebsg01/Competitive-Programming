#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,b,a) for (int i = (b - 1); i >= a; --i)
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define PUSH(s, x) s.push(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define MAXN ((int) (1e6))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

lli T, N, K, ans;
pqlli Q;

void printSolution() {
	int i = 0;
	lli val;
	pqlli t = pqlli(Q);

	while (!t.empty()) {
		if (i > 0) {
			cout << ' ';
		}
	
		val = 1 << t.top();
		cout << val;
		t.pop();
		++i;
	}
	cout << '\n';
}

void findPowers(lli n) {
	lli power;

	while (n > 0) {
		power = (lli) log2(n);
		PUSH(Q, power);
		n -= 1 << power;
	}
}

void solve() {
	lli current, t;

	while (Q.size() < K) {
		current = Q.top();
		Q.pop();

		if (current == 0) {
			PUSH(Q, 0);
			break;
		} else {
			PUSH(Q, current - 1);
			PUSH(Q, current - 1);
		}
	}
}

int main() {
	optimize_io
	cin >> N >> K;
	findPowers(N);
	solve();

	if (Q.size() != K) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		printSolution();
	}
	return 0;
}
