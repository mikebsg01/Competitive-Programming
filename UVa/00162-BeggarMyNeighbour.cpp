#include <iostream>
#include <iomanip>
#include <deque>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define ddcard(x) cout << "[" << x.first << x.second << "]" << endl;
#define REP(i,a,b) for (int i = a; i < b; ++i)
#define PUSHF(s,x) s.push_front(x)
#define PUSHB(s,x) s.push_back(x)
#define POPF(s) s.pop_front()
#define POPB(s) s.pop_back()
#define FRONT(s) s.front()
#define BACK(s) s.back()
#define MP make_pair
#define X first
#define Y second
#define CARDS 52
#define PLAYERS 2
using namespace std;
typedef pair<char, char> Pair;

deque<Pair> player[2];

inline Pair parseCard(string s) {
	return MP(s[0], s[1]);
}

inline int penalty(char c) {
	if (c == 'J') return 1;
	else if (c == 'Q') return 2;
	else if (c == 'K') return 3;
	else if (c == 'A') return 4;
	return 0;
}

void printDeque(deque<Pair> t) {
	Pair current;
	cout << "Deque: ";
	while (!t.empty()) {
		current = FRONT(t);
		cout << current.X << current.Y << ' ';
		POPF(t);
	}
	cout << endl;
}

bool finish(int idx) {
	if (player[idx].empty()) {
		idx ^= 1;
		cout << (2 - idx) << right << setw(3) << player[idx].size() << '\n';
		return true;
	}

	return false;
}

void playGame() {
	int i, p, q, idx, opposite, turn = 0;
	Pair current;
	deque<Pair> t;

	while (true) {
		idx = turn % PLAYERS;

		if (finish(idx)) {
			return;
		}

		current = FRONT(player[idx]);
		PUSHB(t, current);
		POPF(player[idx]);
		p = penalty(current.Y);
		++turn;

		if (p > 0) {
			do {
				q = p;
				p = 0;
				opposite = turn % 2;
				++turn;

				while (q > 0) {
					if (finish(opposite)) {
						return;
					}

					current = FRONT(player[opposite]);
					PUSHB(t, current);
					POPF(player[opposite]);
					p = penalty(current.Y);
	
					if (p > 0) {
						break;
					}

					--q;
				}
			} while (p > 0);

			idx = turn % 2;

			while (!t.empty()) {
				current = FRONT(t);
				PUSHB(player[idx], current);
				POPF(t);
			}
		}
	}
}

int main() {
	optimize_io
	string s;

	while (true) {
		REP(i, 0, CARDS) {
			cin >> s;
			PUSHF(player[(i % 2)], parseCard(s));

			if (i == 0 and s == "#") {
				return 0;
			}
		}

		playGame();
		player[0].clear();
		player[1].clear();
	}
	return 0;
}
