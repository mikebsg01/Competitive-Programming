#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i != b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i != b; --i)
#define CFOR(t,i,a,b,c) for (t i = a; i < b; i += c)
#define VUPPER(s,x) upper_bound(ALL(s), x) - s.begin()
#define VLOWER(s,x) lower_bound(ALL(s), x) - s.begin()
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define PUSH(s, x) s.push(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define SZ size()
#define MAXN 365
#define LIMIT 20
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

int N, 
    P[MAXN + 5], pa, pb, 
    Q[MAXN + 5], qa, qb,
    ans;

int calcDirtiness(int day) {
    int res = 0;
    FOR(int, i, qa, qb) {
        res += (day - Q[i]);
    }
    return res;
}

int main() {
	optimize_io
    int x, dirtiness;
    cin >> N;

    FOR(int, i, 0, N) {
        cin >> x;
        P[pb++] = x;
    }

    FOR(int, day, 1, MAXN + 1) {
        if (day == P[pa]) {
            Q[qb++] = P[pa++];
        }

        if (calcDirtiness(day) < LIMIT and calcDirtiness(day + 1) >= LIMIT) {
            qa = qb;
            ++ans;
        }
    }

    if (qa < qb) {
        ++ans;
    }

    cout << ans << '\n';
	return 0;
}