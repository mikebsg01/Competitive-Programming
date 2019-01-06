#include <iostream>
#include <cstdlib>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define CFOR(i,a,b,c) for (int i = (a); i < (b); i += (c))
#define MAXN 102
#define CARDS 52
#define SUIT 13
using namespace std;

int T;
short N, cards[CARDS + 2], t[CARDS + 2], shuffle[MAXN][CARDS + 2];
string suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" }; 
string ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

void change(short k) {
	FOR(i, 1, CARDS + 1) {
		t[i] = cards[shuffle[k][i]];
	}

	FOR(i, 1, CARDS + 1) {
		cards[i] = t[i];
	}
}

int main() {
	optimize_io
	short k;
	string s;
	cin >> T;

	FOR(t, 0, T) {
		cin >> N;

		FOR(i, 1, N + 1) {
			FOR(j, 1, CARDS + 1) {
				cin >> shuffle[i][j];
			}
		}

		cin.ignore();

		FOR(i, 1, CARDS + 1) {
			cards[i] = i;
		}

		while (true) {
			getline(cin, s);

			if (s == "") {
				break;
			}

			k = atoi(s.c_str());
			change(k);
		}

		if (t > 0) {
			cout << '\n';
		}

		FOR(i, 1, CARDS + 1) {
			cout << ranks[cards[i] % SUIT]  << " of " << suits[(cards[i] - 1) / SUIT] << '\n';
		}
	}
	return 0;
}
