#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
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
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef vector<bool> vectorbl;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef map<int, int> mapi;

lli N, K;

int main() {
	optimize_io
	int i;
	lli x, val, result, substract = 0;
	setlli s;
	cin >> N >> K;

	for (i = 0; i < N; ++i) {
		cin >> x;
		INS(s, x);
	}

	setlli::iterator it = s.begin();

	for (i = 0; i < K; ++i) {
		if (it != s.end()) {
			val = (*it);
			result = (val - substract);
			cout << result << '\n';
			substract += result;
			++it;
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
