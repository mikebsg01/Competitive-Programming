#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i != b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i != b; --i)
#define CFOR(t,i,a,b,c) for (t i = a; i != b; i += c)
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
#define SZ size()
#define MAXN ((int) (2*1e5+5))
#define EPS (1e-8)
#define INF -1
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<lli, lli> Pair;
typedef pair<lli, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef vector<Tern> vectorTern;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef map<int, vectori> cmap;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int N, M;
int U[MAXN], V[MAXN];
vectori E[MAXN];
short vis[MAXN];
bool isImpossible;

void dfs(int node, short direction) {
    if (isImpossible) {
        return;
    } else if (vis[node] != INF) {
        if (vis[node] != direction) {
            isImpossible = true;
        }
        return;
    }

    vis[node] = direction;

    FOR(int, i, 0, E[node].SZ) {
        dfs(E[node][i], direction ^ 1);
    }
}

int main() {
	optimize_io
	cin >> N >> M;

    FOR(int, i, 0, M) {
        cin >> U[i] >> V[i];
        PB(E[U[i]], V[i]);
        PB(E[V[i]], U[i]);
    }

    memset(vis, INF, sizeof(vis));
    isImpossible = false;
    dfs(1, 1);

    if (isImpossible) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        FOR(int, i, 0, M) {
            cout << ((vis[U[i]] == 0 and vis[V[i]] == 1) ^ 1);
        }
        cout << '\n';
    }
	return 0;
}
