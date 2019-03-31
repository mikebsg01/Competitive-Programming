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
typedef map<lli, Pair> cmap;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int N;
vectorlli A;
maplli M;
Tern mostCommonPos;
vectorTern ans;

bool isEqual() {
    FOR(int, i, 1, N) {
        if (A[i] != A[i - 1]) {
            return false;
        }
    }
    return true;
}

vectorTern solve(const Tern& element) {
    lli diff;
    vectorlli T = vectorlli(A);
    vectorTern res;

    RFOR(int, i, element.Y.X - 1, -1) {
        diff = abs(T[i] - T[i + 1]);

        if (T[i] > T[i + 1]) {
            T[i] -= diff;
            PB(res, MP(2, MP(i, i + 1)));
        } else if (T[i] < T[i + 1]) {
            T[i] += diff;
            PB(res, MP(1, MP(i, i + 1)));
        }
    }

    FOR(int, i, element.Y.Y + 1, N) {
        diff = abs(T[i - 1] - T[i]);

        if (T[i - 1] < T[i]) {
            T[i] -= diff;
            PB(res, MP(2, MP(i, i - 1)));
        } else if (T[i - 1] > T[i]) {
            T[i] += diff;
            PB(res, MP(1, MP(i, i - 1)));
        }
    }

    return res;
}

int main() {
	optimize_io
    lli x, mostCommonElement = 0;
	cin >> N;

    FOR(int, i, 0, N) {
        cin >> x;
        PB(A, x);
        ++M[x];

        if (M[x] > mostCommonElement) {
            mostCommonElement = M[x];
            mostCommonPos = MP(mostCommonElement, MP(i, i));
        }
    }

    if (isEqual()) {
        cout << "0\n";
    } else {
        ans = solve(mostCommonPos);
        cout << ans.SZ << '\n';

        FOR(int, i, 0, ans.SZ) {
            cout << ans[i].X << ' ' << (ans[i].Y.X + 1) << ' ' << (ans[i].Y.Y + 1) << '\n';
        }
    }
	return 0;
}
