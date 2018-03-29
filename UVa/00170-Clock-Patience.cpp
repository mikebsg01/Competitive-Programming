#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#define PB push_back
#define SUITS 4
#define CARDS_PER_SUIT 13
using namespace std;

inline int getPile(char c) {
	if (c == 'A') return 1;
	if (c == 'T') return 10;
	if (c == 'J') return 11;
	if (c == 'Q') return 12;
	if (c == 'K') return 13;
	return ((int)(c-'0'));
}

inline int getPileIndex(char pile) {
	return CARDS_PER_SUIT - getPile(pile);
}

int hasFaceDownCards(bool vis[SUITS][CARDS_PER_SUIT], int currentPileIndex) {
	int i;

	for (i = 0; i < SUITS; ++i) {
		if (!vis[i][currentPileIndex]) {
			return i;
		}
	}
	return -1;
}

void play(vector<string> v[SUITS]) {
	int i, j, currentPileIndex, row, previusRow = 0, previusPileIndex = 0, ans = 1;
	bool vis[SUITS][CARDS_PER_SUIT] = {0};
	
	currentPileIndex = getPileIndex(v[0][0][0]);
	vis[0][0] = true;
	
	while ((row = hasFaceDownCards(vis, currentPileIndex)) != -1) {
		vis[row][currentPileIndex] = true;
		previusRow = row;
		previusPileIndex = currentPileIndex;
		currentPileIndex = getPileIndex(v[row][currentPileIndex][0]);
		++ans;
	}

	cout << (ans < 10 ? "0" : "") << ans << "," << v[previusRow][previusPileIndex] << endl;
}

int main() {
	int i = 0, j = 0, k;
	string s;
	vector<string> v[SUITS];
	
	while (true) {
		cin >> s;

		if (s == "#" or s == "") {
			break;
		}

		v[i].PB(s);
		++j;

		if (j == CARDS_PER_SUIT) {
			++i;
			j = 0;
		}

		if (i == SUITS) {
			play(v);
			i = j = 0;

			for (k = 0; k < SUITS; ++k) {
				v[k].clear();
			}
		}
	}
	return 0;
}
