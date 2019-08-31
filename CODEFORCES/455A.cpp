#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define ITFOR(t,i,a,b) for (t i = a; i != b; ++i)
#define PB(s,x) s.push_back(x)
#define MP make_pair
#define X first
#define Y second
#define SZ size()
#define MAXN ((int)(1e5+5))
#define INF -1
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> Pair;
typedef vector<Pair> vectorPair;
typedef map<lli, lli> maplli;

int N;
maplli C;
vectorPair A;
lli DP[MAXN];

lli dp(int idx, lli avoid) {
    if (idx == A.SZ) {
        return 0;
    } else if (A[idx].X == avoid) {
        return dp(idx + 1, avoid);
    } else if (DP[idx] != INF) {
        return DP[idx];
    }

    return DP[idx] = max(
        A[idx].X * A[idx].Y + dp(idx + 1, A[idx].X + 1),
        dp(idx + 1, avoid)
    );
}

int main() {
    optimize_io
    lli x;
    memset(DP, INF, sizeof(DP));
    cin >> N;

    FOR(int, i, 0, N) {
        cin >> x;
        ++C[x]; 
    }

    ITFOR(maplli::iterator, it, C.begin(), C.end()) {
        PB(A, MP(it->first, it->second));
    }

    cout << dp(0, 0) << '\n';
    return 0;
}