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
	double x, y;
	Point() : x(0), y(0) {};
	Point(double _x, double _y) : x(_x), y(_y) {};

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

int C, N;
vector<Point> A;
double ans;

int main() {
	optimize_io
	int idx;
	double x, y, currentHeight, d, m, b;
	Point p;
	cin >> C;

	FOR(i, 0, C) {
		cin >> N;
		ans = 0.0;

		FOR (j, 0, N) {
			cin >> x >> y;
			p = Point(x, y);
			PB(A, p);
		}

		sort(ALL(A));
		idx = N - 2;
		d = A[idx].distance(A[idx + 1]);
		currentHeight = A[idx].y;
		ans += d;

		CFOR(j, idx - 1, -1, -1) {
			if (A[j].y > currentHeight) {
				m = A[j].slope(A[j + 1]);
				b = A[j].y - m * A[j].x;
				x = (currentHeight - b) / m;
				p = Point(x, currentHeight);
				d = A[j].distance(p);
				ans += d;
				currentHeight = A[j].y;
			}
		}

		cout << fixed << setprecision(2) << ans << '\n';
		A.clear();
	}
	return 0;
}
