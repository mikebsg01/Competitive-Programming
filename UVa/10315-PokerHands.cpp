#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define RFOR(i,a,b) for (int i = (a); i > (b); --i)
#define CFOR(i,a,b,c) for (int i = (a); i < (b); i += (c))
#define PUSH(s,x) s.push(x)
#define PB(s,x) s.push_back(x)
#define MP make_pair
#define MT make_tuple
#define X first
#define Y second
#define SZ size()
#define ALL(s) s.begin(), s.end()
#define HAND 5
#define INF -1
using namespace std;
typedef pair<short, char> Pair;
typedef pair<bool, short> PairHand;
typedef pair<short, short> PairRank;
typedef vector<Pair> vectorPair;
typedef priority_queue<short> PQ;

vectorPair players[2];
PairRank hand[2];

inline short getVal(char c) {
	if (isdigit(c)) {
		return ((short)(c - '2'));
	} else if (c == 'T') {
		return 8;
	} else if (c == 'J') {
		return 9;
	} else if (c == 'Q') {
		return 10;
	} else if (c == 'K') {
		return 11;
	} else if (c == 'A') {
		return 12;
	}
}

Pair toCard(string s) {
	short v = getVal(s[0]);
	return MP(v, s[1]);
}

bool sameSuit(vectorPair& v, short start, short end) {
	char c = v[start].Y;
	FOR(i, start + 1, end) {
		if (v[i].Y != c) {
			return false;
		}
	}
	return true;
}

bool isStraight(vectorPair& v, short start, short end) {
	short val = v[start].X;
	FOR(i, start + 1, end) {
		if ((val + 1) == v[i].X) {
			val = v[i].X;
		} else {
			return false;
		}
	}
	return true;
}

PairHand sameValue(vectorPair& v, short start, short end) {
	short val = v[start].X;
	FOR(i, start + 1, end) {
		if (val != v[i].X) {
			return MP(false, INF);
		}
	}
	return MP(true, val);
}

PairHand isStraightFlush(vectorPair& v) {
	bool straightFlush = sameSuit(v, 0, HAND) and isStraight(v, 0, HAND);
	return MP(straightFlush, (straightFlush ? v[HAND - 1].X : INF));
}

PairHand isFourOfAKind(vectorPair&v) {
	PairHand t;
	FOR(i, 0, 2) {
		t = sameValue(v, i, i + 4);

		if (t.X) {
			return MP(true, t.Y);
		}
	}
	return MP(false, INF);
}

PairHand isFullHouse(vectorPair& v) {
	PairHand t[2];
	FOR(i, 0, 2) {
		t[0] = sameValue(v, 0, HAND - 2 - i);
		t[1] = sameValue(v, HAND - 2 - i, HAND);

		if (t[0].X and t[1].X) {
			return MP(true, t[i].Y);
		}
	}
	return MP(false, INF);
}

PairHand isFlush(vectorPair& v) {
	bool same = sameSuit(v, 0, HAND);
	return MP(same, (same ? v[HAND - 1].X : INF));
}

PairHand isStraight(vectorPair& v) {
	bool straight = isStraight(v, 0, HAND);
	return MP(straight, (straight ? v[HAND - 1].X : INF));
}

PairHand isThreeOfAKind(vectorPair& v) {
	PairHand t;
	FOR(i, 0, 3) {
		t = sameValue(v, i, i + 3);

		if (t.X) {
			return MP(true, t.Y);
		}
	}
	return MP(false, INF);
}

PairHand isTwoPairs(vectorPair& v) {
	PairHand t[2];
	FOR(i, 0, 2) {
		t[0] = sameValue(v, i, i + 2);

		if (t[0].X) {
			FOR(j, i + 2, HAND - 1) {
				t[1] = sameValue(v, j, j + 2);

				if (t[1].X) {
					return MP(true, max(t[0].Y, t[1].Y));
				}
			}
		}
	}
	return MP(false, INF);
}

PairHand isPair(vectorPair& v) {
	PairHand t;
	FOR(i, 0, 4) {
		t = sameValue(v, i, i + 2);
		if(t.X) {
			return MP(true, t.Y);
		}
	}
	return MP(false, INF);
}

PairRank getHand(vectorPair& v) {
	PairHand t, (*func[8]) (vectorPair& v) = {
		isStraightFlush,
		isFourOfAKind,
		isFullHouse,
		isFlush,
		isStraight,
		isThreeOfAKind,
		isTwoPairs,
		isPair
	};

	sort(ALL(v));

	FOR(i, 0, 8) {
		t = (*func[i])(v);

		if (t.X) {
			return MP(i + 1, t.Y);
		}
	}

	return MP(9, v[HAND - 1].X);
}

short getWinner() {
	if (hand[0].X < hand[1].X) {
		return 0;
	} else if (hand[0].X > hand[1].X) {
		return 1;
	} else if (hand[0].Y > hand[1].Y) {
		return 0;
	} else if (hand[0].Y < hand[1].Y) {
		return 1;
	} else if (hand[0].X == 9 or hand[0].X == 4) {
		RFOR(i, HAND - 1, -1) {
			if (players[0][i].X > players[1][i].X) {
				return 0;
			} else if (players[0][i].X < players[1][i].X) {
				return 1;
			}
		}
	} else if (hand[0].X == 8) {
		short p[2], h = hand[0].Y;
		PQ t[2];

		FOR(i, 0, HAND) {
			p[0] = players[0][i].X, p[1] = players[1][i].X;

			if (p[0] != h) {
				PUSH(t[0], p[0]);
			}

			if (p[1] != h) {
				PUSH(t[1], p[1]);
			}
		}
	
		while(!t[0].empty() and !t[1].empty()) {
			p[0] = t[0].top(); t[0].pop();
			p[1] = t[1].top(); t[1].pop();

			if (p[0] > p[1]) {
				return 0;
			} else if (p[0] < p[1]) {
				return 1;
			}
		}
	} else if (hand[0].X == 7) {
		short sp[2], r[2], fp = hand[0].Y;

		FOR(i, 0, HAND - 1) {
			if (players[0][i].X != fp and players[0][i].X == players[0][i + 1].X) {
				sp[0] = players[0][i].X;
			}

			if (players[1][i].X != fp and players[1][i].X == players[1][i + 1].X) {
				sp[1] = players[1][i].X;
			}
		}

		if (sp[0] > sp[1]) {
			return 0;
		} else if (sp[0] < sp[1]) {
			return 1;
		} else {
			short p[2];
			FOR(i, 0, HAND) {
				p[0] = players[0][i].X, p[1] = players[1][i].X;

				if (p[0] != fp and p[0] != sp[0]) {
					r[0] = p[0];
				}

				if (p[1] != fp and p[1] != sp[1]) {
					r[1] = p[1];
				}
			}

			if (r[0] > r[1]) {
				return 0;
			} else if (r[0] < r[1]) {
				return 1;
			}
		}
	}
	return INF;
}

int main() {
	optimize_io
	string s;
	short winner;
	
	while(cin >> s) {
		PB(players[0], toCard(s));

		FOR(i, 0, 2 * HAND - 1) {
			cin >> s;
			PB(players[(i + 1) / HAND], toCard(s));
		}
		
		FOR(i, 0, 2) {
			hand[i] = getHand(players[i]);
		}

		winner = getWinner();

		if (winner != INF) {
			cout << ((winner == 0) ? "Black wins.\n" : "White wins.\n");
		} else {
			cout << "Tie.\n";
		}

		FOR(i, 0, 2) {
			players[i].clear();
		}
	}
	return 0;
}
