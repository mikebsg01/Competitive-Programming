#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for (int i = a; i > b; --i)
#define CFOR(i,a,b,c) for (int i = a; i != b; i += c)
#define PB(s,x) s.push_back(x)
#define SZ size()
#define ALL(s) s.begin(), s.end()
using namespace std;

class Point {
public:
	double x, y, r;

	Point() : x(0), y(0), r(0) {};
	Point(double _x, double _y, double _r) : x(_x), y(_y), r(_r) {};

	bool operator<(const Point& cmp) {
		return (x != cmp.x) ? (x < cmp.x) : (y < cmp.y);
	}

	double distance(const Point& b) {
		return hypot(b.y - y, b.x - x);
	}

	double slope(const Point& b) {
		return (b.y - y) / (b.x - x);
	}
};

int R, D, N, ans;
vector<Point> A;

int main() {
	optimize_io
	double x, y, r, d, a, b;
	Point p, q;
	cin >> R >> D >> N;
	p = Point(0, 0, R - D);

	FOR(i, 0, N) {
		cin >> x >> y >> r;
		q = Point(x, y, r);
		d = q.distance(p);
		a = d - (p.r + q.r);
		b = d + q.r;

		if (a >= 0 and b <= R) {
			++ans;
		}
	}

	cout << ans << '\n';
	return 0;
}
