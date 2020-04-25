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

lli N, C;
setlli S;
maplli M;

lli calcMinVolunteers(lli N, lli C, setlli& S) {
    lli current, x, y, ans = 0;
    setlli::iterator it;
    C *= -1;

    while (!S.empty()) {
        current = *S.begin();
        M[current] -= 1;
        
        if (M[current] == 0) {
            ERASE(S, current);
        }

        x = C - current;

        if (x < 0 and !S.empty()) {
            it = LOWER(S, x);

            if (it != S.end()) {
                y = (*it);

                M[y] -= 1;

                if (M[y] == 0) {
                    ERASE(S, y);
                }
            }
        }

        ++ans;
    }

    return ans;
}

int main() {
	optimize_io
    lli x;
	cin >> N >> C;

    FOR(int, i, 0, N) {
        cin >> x;
        x *= -1;
        INS(S, x);

        if (M.count(x) > 0) {
            M[x] += 1;
        } else {
            M[x] = 1;
        }
    }

    cout << calcMinVolunteers(N, C, S) << "\n";
	return 0;
}
