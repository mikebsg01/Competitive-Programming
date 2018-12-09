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
typedef set<string> setstr;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;

int T;
double D;
int N; string P;
setstr S;
bool solved = false;

int countK() {
	int counter = 0;
	for (int i = 0; i < N; ++i) {
		if (P[i] == 'K') {
			++counter;
		}
	}
	return counter;
}

void backtrack(lli changes) {
	if (solved or S.count(P) > 0) {
		return;
	} else {
		INS(S, P);
		double t, d = 1, sum = 0;

		for (int i = 0; i < N; ++i) {
			if (P[i] == 'M') {
				d *= 3;
			} else if (P[i] == 'K') {
				sum += d;
			} else if (P[i] == 'S') {
				t = d / 2;
				
				if (t >= 1.0) {
					d /= 2;
				}
			}
		}

		if (sum <= D) {
			solved = true;
			dd(P);
			dd(sum);
			dd(changes);
			return;
		}
	}

	for (int i = 0; i < (N - 1); ++i) {
		swap(P[i], P[i + 1]);
		backtrack(changes + 1);
		swap(P[i], P[i + 1]);
	}
}

int main() {
	optimize_io
	cin >> T;
	while (T--) {
		cin >> D >> P;
		if (countK() > D) {
			cout << "IMPOSSIBLE\n";
		}

		N = P.size();
		backtrack(0);
		S.clear();
		P.clear();
		solved = false;
	}
	return 0;
}
