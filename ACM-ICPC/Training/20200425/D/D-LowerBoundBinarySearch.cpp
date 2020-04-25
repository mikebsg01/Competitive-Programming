#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i > b; --i)
#define CFOR(t,i,a,b,c) for (t i = a; i < b; i += c)
#define ITFOR(t,i,a,b) for (t i = a; i != b; ++i)
#define MP make_pair
#define X first
#define Y second
#define PB(s, x) s.push_back(x)
#define VUPPER(s,x) upper_bound(ALL(s), x) - s.begin()
#define VLOWER(s,x) lower_bound(ALL(s), x) - s.begin()
#define INS(s, x) s.insert(x)
#define FIND(s,x) s.find(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define PUSH(s, x) s.push(x)
#define ALL(s) s.begin(), s.end()
#define SZ size()
#define MAXN ((int) (1e6))
#define EPS (1e-8)
#define INF -1
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<lli, lli> Pair;
typedef pair<lli, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef pair<Pair, string> cPair;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef vector<Tern> vectorTern;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef map<lli, char> cmap;
typedef queue<int> qi;
typedef queue<lli> qlli;
typedef queue<Pair> qPair;
typedef queue<cPair> cq;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

class Point {
public:
    double x, y, z;

    Point() :
        x(0), y(0), z(0) {}

    Point(double _x, double _y, double _z) :
        x(_x), y(_y), z(_z) {}

    double dist() {
        return sqrt(x * x + y * y + z * z);
    }
};

lli N, K;
vector<Point> points;
vector<double> distances;

int f(double radius) {
    int ans = 0;
    double d;

    for (auto point : points) {
        d = point.dist();

        if (d <= radius) {
            ++ans;
        }
    }

    return ans;
}

int binary(int a, int b, int x) {
    int m;
    double radius;

    while (a < b) {
        m = (a + b) / 2;
        radius = distances[m];

        if (f(radius) < x) {
            a = m + 1;
        } else {
            b = m;
        }
    }

    return a;
}

double calcMinRadius() {
    int pos;
    double d;

    for (auto point : points) {
        d = point.dist();
        PB(distances, d);
    }

    sort(ALL(distances));
    pos = binary(0, N, K);
    return distances[pos];
}

int main() {
	optimize_io
    double x, y, z, ans;
    Point point;
    cin >> N >> K;

    FOR(int, i, 0, N) {
        cin >> x >> y >> z;
        point = Point(x, y, z);
        PB(points, point);
    }

    ans = calcMinRadius();
    printf("%1.8f\n", ans);
	return 0;
}
