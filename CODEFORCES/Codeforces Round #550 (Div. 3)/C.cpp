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
#define MAXN ((int) (1e4+5))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef map<int, vectori> cmap;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int N;
pqlli P;
deque<lli> S[2];

bool solve() {
    lli t;

    while (!P.empty()) {
        t = P.top(); P.pop();

        if (S[1].empty() or S[1].back() > t) {
            S[1].push_back(t);
        } else if (S[0].empty() or S[0].back() > t) {
            S[0].push_back(t);
        } else {
            return false;
        }
    }

    return true;
}

int main() {
	optimize_io
    int j;
    lli x;
	cin >> N;

    FOR(int, i, 0, N) {
        cin >> x;
        PUSH(P, x);
    }

    if (!solve()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        FOR(int, i, 0, 2) {
            cout << S[i].SZ << '\n';

            j = 0;
            while (!S[i].empty()) {
                if (i > 0) {
                    x = S[i].front(); S[i].pop_front();
                } else {
                    x = S[i].back(); S[i].pop_back();
                }

                if (j > 0) {
                    cout << ' ';
                }

                cout << x;
                ++j;
            }

            cout << '\n';
        }
    }
	return 0;
}
