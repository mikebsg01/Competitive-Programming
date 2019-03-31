#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for (int i = a; i > b; --i)
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
#define SZ size()
#define MAXN ((int) (1e4+5))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef set<char> cset;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef map<int, vectori> cmap;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int N;
string S;
cset H;

int main() {
	optimize_io
	char a, b;
	bool isDiverse;
	cin >> N;
	FOR(i, 0, N) {
		cin >> S;
		H.clear();

		FOR(j, 0, S.SZ) {
			INS(H, S[j]);
		}

		if (S.SZ == 1) {
			cout << "Yes\n";
			continue;
		} else if (H.SZ != S.SZ) {
			cout << "No\n";
			continue;
		}

		cset::iterator it1 = H.begin();
		cset::iterator it2 = H.begin();
		++it2;
		isDiverse = true;

		for (; it2 != H.end(); ++it1, ++it2) {
			a = (*it1);
			b = (*it2);
			
			if ((a + 1) != b) {
				cout << "No\n";
				isDiverse = false;
				break;
			}
		}

		if (isDiverse) {
			cout << "Yes\n";
		}
	}
	return 0;
}
