#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,b,a) for (int i = b; i > a; --i)
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
#define MAXN 405
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
typedef set<Tern> setTern;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int R, C, r, c;
char T[MAXN][MAXN];
int dist[MAXN][MAXN];

int mov[2][4] =	{{ 0, 1, 0, -1},
		 {-1, 0, 1,  0}};

void printMap(int cars, int y, int x) {
	cout << "\nCurrent Map:\n";
	FOR(i, 1, R + 1) {
		FOR(j, 1, C + 1) {
			if (i == y and j == x) {
				cout << cars;
			} else {
				cout << T[i][j];
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

int dijkstra(int x, int y) {
	int xt, yt, cars, add, ans = INT_MAX;
	Tern t;
	setTern S;
	setTern::iterator it;
	INS(S, MP(1, MP(x, y)));
	dist[y][x] = 0;

	while (!S.empty()) {
		it = S.begin();
		t = (*it);
		cars = t.X;
		x = t.Y.X;
		y = t.Y.Y;
		S.erase(it);
		/* printMap(cars, y, x); */

		if (T[y][x] == 'D' and (x == 1 or x == C or y == 1 or y == R)) {
			/* printMap(cars, y, x); */
			ans = min(ans, cars);
			continue;
		}

		FOR(i, 0, 4) {
			xt = x + mov[0][i];
			yt = y + mov[1][i];

			if (T[yt][xt] == '#' or xt < 1 or xt > C or yt < 1 or yt > R) continue;

			add = (T[yt][xt] == 'c') ? 1 : 0;

			if ((cars + add) < dist[yt][xt]) {
				dist[yt][xt] = cars + add;
				INS(S, MP(dist[yt][xt], MP(xt, yt)));
			}
		}
	}
	return ans;
}

int main() {
	optimize_io
	cin >> R >> C;

	FOR(i, 1, R + 1) {
		FOR(j, 1, C + 1) {
			cin >> T[i][j];
			dist[i][j] = INT_MAX;
		}
	}

	cin >> r >> c;
	cout << dijkstra(c, r) << '\n';
	return 0;
}
