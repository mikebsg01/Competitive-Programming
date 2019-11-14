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
typedef pair<int, int> Pair;
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

int N, M, K, D;
vectorPair A;

void solve() {
    int AN = A.SZ, 
        a = min(N, A[0].X + D), 
        b = max(1, A[AN - 1].X - D);
        
        if (a > b) {
            swap(a, b);
        }

    FOR(int, i, a, b + 1) {
        FOR(int, j, 0, AN) {
            
        }
    }
}

int main() {
	optimize_io
    int x, y;
    cin >> N >> M;
    cin >> K;

    FOR(int, i, 0, K) {
        cin >> x >> y;
        PB(A, MP(x, y));
    }

    cin >> D;
    sort(ALL(A));
    solve();
	return 0;
}
