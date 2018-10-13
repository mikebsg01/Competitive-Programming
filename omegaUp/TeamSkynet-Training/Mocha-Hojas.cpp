#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define MAXN 100002
#define PB push_back
using namespace std;
typedef unsigned long long int lli;
typedef set<lli> slli;

int N;
vector<lli> V;
vector<int> E[MAXN];
bitset<MAXN> vis;
bitset<MAXN> isLeaf;
slli factors;
lli lcm = 1;

inline int numChildren(int node) {
	int n = E[node].size();
	return (node == 0) ? n : (n - 1);
}

lli getFactors(int node, lli factor) {
	int n = E[node].size();
	vis[node] = 1;

	if (V[node]) {
		factors.insert(factor);
		isLeaf[node] = 1;
		return V[node];
	}

	int i, m;
	lli s = 0, a = factor;

	factors.insert(factor);

	for (i = 0; i < n; ++i) {
		if (! vis[E[node][i]]) {
			m = numChildren(node);
			m = (m > 0) ? m : 1;
			s += getFactors(E[node][i], factor * m);
		}
	}

	return V[node] = s;
}

lli __lcm(lli a, lli b) {
	return a * (b / __gcd(a, b));
}

void getLcm() {
	int i;
	slli::iterator it = factors.begin();

	while (it != factors.end()) {
		if ((*it) == 0) {
			++it;
			continue;
		}

		lcm = __lcm(lcm, (*it));
		++it;
	}
}

bool isSolution(int node, lli val) {
	int n = E[node].size();

	vis[node] = 1;

	if (val > V[node]) {
		return false;
	}

	if (isLeaf[node]) {
		return true;
	}

	int i;
	bool solution = true;

	for (i = 0; i < n; ++i) {
		if (! vis[E[node][i]] and ! isSolution(E[node][i], val / numChildren(node))) {
			solution = false;
		}
	}

	return solution;
}

lli binary(lli a, lli b) {
	lli m = 0;

	while (a < b) {
		m = (a + b) / 2;
		vis.reset();

		if (isSolution(0, lcm * m)) {
			a = m + 1;
		} else {
			b = m;
		}
	}
	
	vis.reset();
	
	if (isSolution(0, lcm * a)) {
		return V[0] - (lcm * a);
	}

	return V[0] - (lcm * (a - 1));
}

int main() {
	optimize_ios
	
	int i, x, y;

	cin >> N;

	for (i = 0; i < N; ++i) { 
		cin >> x;
		V.PB(x);
	}

	for (i = 0; i < (N - 1); ++i) {
		cin >> x >> y;
		E[x - 1].PB(y - 1);
		E[y - 1].PB(x - 1);
	}

	vis.reset(); isLeaf.reset();
	getFactors(0, 1);
	getLcm();
	cout << binary(0, V[0] / lcm) << '\n';
	return 0;
}
