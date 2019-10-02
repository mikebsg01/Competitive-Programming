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
#define MAXN ((int) (1e5+5))
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

int N;
vectorlli A, E[MAXN];
bool vis[MAXN];

lli grundy(lli n) {
    lli t = (n / 2);
    return ((lli) (t % 2 != 0));
}

inline lli div(lli a, lli b) {
    return ((lli) (a / b));
}

lli dfs(int node, int deep) {
    if (vis[node]) {
        return 0;
    }

    vis[node] = true;
    lli result = (node == 1) ? 0 : ((((lli) A[node - 1] / 2) % 2) * deep);

    FOR(int, i, 0, E[node].SZ) {
        result ^= dfs(E[node][i], deep + 1);
    }

    return result;
}

int main() {
	optimize_io
    lli x, y;
    cin >> N;

    FOR(int, i, 0, N) {
        cin >> x;
        PB(A, x);
    }

    FOR(int, i, 0, N - 1) {
        cin >> x >> y;
        PB(E[x], y);
        PB(E[y], x);
    }

    if (dfs(1, 0)) {
        cout << "Gana el primer jugador.\n";
    } else {
        cout << "Gana el segundo jugador.\n";
    }
	return 0;
}
