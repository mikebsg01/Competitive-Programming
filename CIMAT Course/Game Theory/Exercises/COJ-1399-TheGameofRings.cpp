##include <bits/stdc++.h>
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
#define MAXN ((int) (1e2+5))
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

int K, L, M;
bool DP[MAXN][MAXN][MAXN];

void dp() {
    FOR(int, i, 0, MAXN) {
        FOR(int, j, 0, MAXN) {
            FOR(int, k, 0, MAXN) {
                if ((i and ! DP[i - 1][j][k]) or
                    (j and ! DP[i][j - 1][k]) or
                    (j >= 2 and ! DP[i][j - 2][k]) or
                    (k and ! DP[i][j][k - 1]) or 
                    (k >= 2 and ! DP[i][j][k - 2]) or
                    (k >= 3 and ! DP[i][j][k - 3])
                    (i + j + k and ! DP[max(0, i - 1)][max(0, j - 1)][max(0, k - 1)])) {
                    DP[i][j][k] = true;
                }
            }
        }
    }
}

int main() {
	optimize_io
    int N;
	cin >> K >> L >> M;
    dp();
    
    whilecin >> a >> b >> c;
        
	return 0;
}
