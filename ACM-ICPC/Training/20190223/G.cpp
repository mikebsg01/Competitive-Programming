#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,b,a) for (int i = (b - 1); i >= a; --i)
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
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int fleet[2];
string ship[2];
string winner[] = {"Tobby", "Naebbirac", "Draw"};

short typeOfShip(string s) {
	if (s == "Battleships") return 0;
	else if (s == "Destroyers") return 1;
	else if (s == "Cruisers") return 2;
	return -1;
}

short getWinner() {
	int t[2];

	FOR(i, 0, 2) {
		t[i] = typeOfShip(ship[i]);
	}

	if (t[0] == t[1]) {
		if (fleet[0] > fleet[1]) {
			return 0;
		} else if (fleet[0] < fleet[1]) {
			return 1;
		}
		return 2;
	} else if	((t[0] == 0 and t[1] == 1) or
			 (t[0] == 1 and t[1] == 2) or
			 (t[0] == 2 and t[1] == 0)) {
		return fleet[1] >= (2 * fleet[0]);
	}
	return fleet[0] < (2 * fleet[1]);
}

int main() {
	optimize_io
	while (cin >> ship[0]) {
		cin >> fleet[0] >> ship[1] >> fleet[1];
		cout << winner[getWinner()] << '\n';
	}
	return 0;
}
