#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vectori;
typedef vector<bool> vectorbl;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef map<int, int> mapi;

int T;
lli N, M;
lli x[6], y[6];

bool getColor(lli y, lli x) {
	lli a = y % 2, b = x % 2;
	return ((bool) (a ^ b));
}

lli getArea(lli y1, lli x1, lli y2, lli x2) {
	return (abs(y1 - y2) + 1) * (abs(x1 - x2) + 1);
}

void countBlacks(lli y1, lli x1, lli y2, lli x2, lli &area, lli &blacks, lli &whites) { 
	bool color = getColor(y1, x1);
	
	area = getArea(y1, x1, y2, x2);
	lli q = area / 2, r = area % 2;
	blacks = color ? (q + r) : q;
	whites = area - blacks;
}

bool intersect(lli y1, lli x1, lli y2, lli x2, lli y3, lli x3, lli y4, lli x4) {
	return !((x2 < x3 or x4 < x1) or (y2 < y3 or y4 < y1));
}

void getIntersection(lli y1, lli x1, lli y2, lli x2, lli y3, lli x3, lli y4, lli x4, lli &y5, lli &x5, lli &y6, lli &x6) {
	y5 = max(y1, y3);
	x5 = max(x1, x3);
	y6 = min(y2, y4);
	x6 = min(x2, x4);
}

int main() {
	optimize_io
	int i;
	lli totalArea, totalBlacks, totalWhites, area, blacks, whites;
	cin >> T;
	
	for (i = 0; i < T; ++i) {
		cin >> N >> M;
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		cin >> x[2] >> y[2] >> x[3] >> y[3];
		countBlacks(1, 1, N, M, totalArea, totalBlacks, totalWhites);
		countBlacks(y[0], x[0], y[1], x[1], area, blacks, whites);
		totalBlacks -= blacks;
		countBlacks(y[2], x[2], y[3], x[3], area, blacks, whites);
		totalBlacks += whites;

		if (intersect(y[0], x[0], y[1], x[1], y[2], x[2], y[3], x[3])) {
			getIntersection(y[0], x[0], y[1], x[1], y[2], x[2], y[3], x[3], y[4], x[4], y[5], x[5]);
			countBlacks(y[4], x[4], y[5], x[5], area, blacks, whites);
			totalBlacks += blacks;
		}

		totalWhites = totalArea - totalBlacks;
		cout << totalWhites << ' ' << totalBlacks << '\n';
	}
	return 0;
}
