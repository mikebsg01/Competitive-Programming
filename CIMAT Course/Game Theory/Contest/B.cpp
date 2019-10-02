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

int T, N;
lli DP[MAXN], Grundy[MAXN], ans;

lli binexp(lli n, lli exp) {
    lli result = 1;

    FOR(lli, i, 0, exp) {
        result *= n;
    }

    return result;
}

void dp() {
    lli exp;
    DP[0] = 0;
    DP[1] = 1;

    FOR(lli, i, 2, MAXN) {
        for (lli j = 1; ; ++j) {
            exp = binexp(j, j);

            if (exp > i) {
                break;
            }

            if (! DP[i - exp]) {
                DP[i] = 1;
            }
        }
    }
}

lli calculateMex(unordered_set<lli> S) { 
    lli mex = 0; 
  
    while (S.find(mex) != S.end()) 
        mex++;
  
    return mex; 
} 

lli calculateGrundy(lli n) {
    if (Grundy[n] != -1) {
        return Grundy[n];
    }

    unordered_set<lli> S;
    lli exp;

    for (int i = 1; i < 8; i++) {
        exp = binexp(i, i);

        if (n >= exp) {
            INS(S, calculateGrundy(n - exp));
        }
    }

    Grundy[n] = calculateMex(S);
    return Grundy[n];
}

void solve() {
    memset(Grundy, INF, sizeof(Grundy));
    Grundy[0] = 0;
    Grundy[1] = 1;

    FOR(int, i, 0, MAXN) {
        calculateGrundy(i);
    }
}

int main() {
	optimize_io
    int x;
	cin >> T;
    solve();

    FOR(int, i, 0, T) {
        cin >> N;
        ans = 0;

        FOR(int, i, 0, N) {
            cin >> x;
            ans ^= Grundy[x];
        }

        if (ans) {
            cout << "Gana el primer jugador.\n";
        } else {
            cout << "Gana el segundo jugador.\n";
        }
    }
	return 0;
}
