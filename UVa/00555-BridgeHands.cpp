#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = int(a); i < int(b); ++i)
#define CFOR(i,a,b,c) for (int i = a; i < b; i += c)
#define INS(s, x) s.insert(x)
#define PB(s, x) s.push_back(x)
#define SZ size()
#define MP make_pair
#define X first
#define Y second
#define DIRECTIONS 4
using namespace std;
typedef pair<short, short> pairii;
typedef vector<pairii> vectorii;
typedef set<pairii> setii;

setii A[DIRECTIONS];
char directions[] = { 'S', 'W', 'N', 'E' };

inline short getDirection(char c) {
	if (c == 'S') return 0;
	else if (c == 'W') return 1;
	else if (c == 'N') return 2;
	return 3;
}

inline short suitId(char c) {
	if (c == 'C') return 0;
	else if (c == 'D') return 1;
	else if (c == 'S') return 2;
	return 3;
}

inline short rankVal(char c) {
	if (isdigit(c)) return ((short)(c-'2'));
	else if (c == 'T') return 8;
	else if (c == 'J') return 9;
	else if (c == 'Q') return 10;
	else if (c == 'K') return 11;
	return 12;
}

inline char getSuit(short id) {
	if (id == 0) return 'C';
	else if (id == 1) return 'D';
	else if (id == 2) return 'S';
	return 'H';
}

inline char getRank(short val) {
	if (val >= 0 and val <= 7) return ((char) (val + '2'));
	else if (val == 8) return 'T';
	else if (val == 9) return 'J';
	else if (val == 10) return 'Q';
	else if (val == 11) return 'K';
	return 'A';
}

int main() {
	optimize_io
	int n, k;
	char d, suit, rank;
	string s;
	pairii t;
	setii::iterator it;

	while (cin >> d, d != '#') {
		k = (getDirection(d) + 1) % DIRECTIONS;

		FOR(i, 0, 2) {
			cin >> s;
			n = s.SZ;
			
			CFOR(j, 0, n, 2) {
				suit = s[j];
				rank = s[j + 1];
				t = MP(suitId(suit), rankVal(rank));
				INS(A[k], t);
				k = (k + 1) % DIRECTIONS;
			}
		}

		FOR(i, 0, DIRECTIONS) {
			cout << directions[i] << ": ";
			
			for (it = A[i].begin(), k = 0; it != A[i].end(); ++it, ++k) {
				t = (*it);

				if (k > 0) {
					cout << ' ';
				}

				cout << getSuit(t.X) << getRank(t.Y);
			}

			cout << '\n';
			A[i].clear();
		}
	}
	return 0;
}
