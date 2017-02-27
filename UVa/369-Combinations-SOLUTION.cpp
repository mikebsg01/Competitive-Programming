#include <bits/stdc++.h>
#define optimize_ios() ios_base::sync_with_stdio(0);cin.tie(0)
#define MAXN 101
using namespace std;

int N, M;
int dp[MAXN][MAXN];

void pascal() {
    int i, j;

    for (i = 0; i < MAXN; ++i)
        dp[i][0] = dp[0][i] = 1;

    for (i = 1; i < MAXN; ++i) {
        for (j = 1; j < MAXN; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
}

int main() {
    optimize_ios();
    int n, m;
    pascal();
    while (cin >> n >> m && (n || m)) {
        cout << n << " things taken " << m << " at a time is " << dp[n-m][m] << " exactly.\n";
    }
    return 0;
}
