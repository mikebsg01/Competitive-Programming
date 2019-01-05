#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = int(a); i < int(b); ++i)
#define PB(s, x) s.push_back(x)
#define SZ size()
#define ALL(s) s.begin(), s.end()
#define MP make_pair
#define X first
#define Y second
#define SUITS 4
#define CARDS 13
#define NOTRUMP 16
#define MINPOINTS 14
using namespace std;
typedef pair<int, char> Pair;
typedef vector<char> vectorchr;

vectorchr A[SUITS];
char suits[] = {'S', 'H', 'D', 'C'};

Pair toCode(string& s) {
	int suit;
	char c = s[1], rank = s[0];

	if (c == 'S') suit = 0;
	else if (c == 'H') suit = 1;
	else if (c == 'D') suit = 2;
	else if (c == 'C') suit = 3;

	return MP(suit, rank);
}

inline bool isStopped(int n, bool ace, bool king, bool queen) {
	return ace or (king and n >= 2) or (queen and n >= 3);
}

void solve() {
	int n, suitIdx, maxCards = 0, points = 0, extras = 0;
	bool ace, king, queen, allStopped = true;
	char rank;

	FOR (i, 0, SUITS) {
		n = A[i].SZ;
		ace = king = queen = false;

		FOR (j, 0, n) {
			rank = A[i][j];

			if (rank == 'A') {
				points += 4;
				ace = true;
			} else if (rank == 'K') { 
				points += 3;
				king = true;
			} else if (rank == 'Q') {
				points += 2;
				queen = true;
			} else if (rank == 'J') {
				points += 1;
			}

			if (rank == 'K' and n <= 1) {
				points -= 1;
			} else if (rank == 'Q' and n <= 2) {
				points -= 1;
			} else if (rank == 'J' and n <= 3) {
				points -= 1;
			}
		}

		if (n > maxCards) {
			maxCards = n;
			suitIdx = i;
		}

		if (!isStopped(n, ace, king, queen)) {
			allStopped = false;	
		}

		if (n == 2) {
			extras += 1;
		} else if (n == 1) {
			extras += 2;
		} else if (n == 0) {
			extras += 2;
		}
	}

	if (points >= NOTRUMP and allStopped) {
		cout << "BID NO-TRUMP\n";
	} else {
		points += extras;

		if (points >= MINPOINTS) {
			cout << "BID " << suits[suitIdx] << "\n";
		} else {
			cout << "PASS\n";
		}
	}
}

int main() {
	optimize_io
	string s;
	Pair t;

	while (cin >> s) {
		t = toCode(s);
		PB(A[t.X], t.Y);

		FOR(i, 0, CARDS - 1) {
			cin >> s;
			t = toCode(s);
			PB(A[t.X], t.Y);
		}

		solve();

		FOR(i, 0, SUITS) {
			A[i].clear();
		}
	}
	return 0;
}
