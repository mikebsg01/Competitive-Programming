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
#define MAXN ((int) (1e3+5))
#define EPS (1e-8)
#define INF LLONG_MIN
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

int N, M;
vectorPair E[MAXN];
bool vis[MAXN];
vectorlli T;
lli dist[MAXN];

void toposortutil(int node) {
    if (vis[node]) {
        return;
    }

    vis[node] = true;

    FOR(int, i, 0, E[node].SZ) {
        toposortutil(E[node][i].X);
    }

    PB(T, node);
}

void toposort() {
    FOR(int, i, 1, N + 1) {
        toposortutil(i);
    }
}

lli dijkstra(int start) {
    int u;    
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;

    RFOR(int, i, N - 1, -1) {
        u = T[i];

        if (dist[u] != INF) {
            FOR(int, j, 0, E[u].SZ) {
                dist[E[u][j].X] = max(dist[E[u][j].X], dist[u] + E[u][j].Y);
            }
        }
    }

    lli ans = INF;

    FOR(int, i, 1, N + 1) {
        ans = max(ans, dist[i]);
    }

    return ans;
}

int main() {
	optimize_io
    int s, t, c;
    cin >> N >> M;

    FOR(int, i, 0, M) {
        cin >> s >> t >> c;
        PB(E[s], MP(t, c));
    }

    toposort();
    cout << dijkstra(T[N - 1]) << '\n';
	return 0;
}