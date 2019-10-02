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
#define MAXN ((int) (1e2+2))
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

int T, A, B;
/*
int DP[MAXN][MAXN];
void dp() {
    int l;

    FOR(int, i, 1, MAXN) {
        FOR(int, j, 1, MAXN) {
            if (i > 1) {
                FOR(int, k, 1, (i / 2) + 1) {
                    l = i - k;

                    if (! DP[k][l]) {
                        DP[i][j] = 1;
                    }
                }
            }

            if (j > 1) {
                FOR(int, k, 1, (j / 2) + 1) {
                    l = j - k;

                    if (k <= i and l <= j and ! DP[k][l]) {
                        DP[i][j] = 1;
                    }
                }
            }
        }
    }
    
    FOR(int, i, 0, 20) {
        FOR(int, j, 0, 20) {
            cout << DP[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
*/

int main() {
	optimize_io
	cin >> T;

    FOR(int, t, 1, T + 1) {
        cin >> A >> B;

        if (((A % 2) == 0) or ((B % 2) == 0)) {
            cout << "Gana el primer jugador.\n";
        } else {
            cout << "Gana el segundo jugador.\n";
        }
    }
	return 0;
}
