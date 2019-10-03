#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define MAXN 155
#define INF -1
using namespace std;

int DP[MAXN][MAXN];

int dp(int a, int b) {
    if (DP[a][b] != INF) {
        return DP[a][b];
    } else if (a == 0 or b == 0 or (a == 1 and b == 1)) {
        return DP[a][b] = DP[b][a] = 0;
    }

    return DP[a][b] = DP[b][a] = 1 + max(dp(max(a - 2, 0), b + 1), dp(a + 1, max(b - 2, 0)));
}

int main() {
    optimize_io
    int a, b;
    memset(DP, INF, sizeof(DP));
    cin >> a >> b;
    cout << dp(a, b) << '\n';
    return 0;
}