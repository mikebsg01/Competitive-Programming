#include <bits/stdc++.h>
#define optimize_ios() ios_base::sync_with_stdio(0);cin.tie(0)
#define MAXN 1000000
using namespace std;
typedef long long int lli;

lli dp[MAXN];

void precalculation() {
    int i;
    lli distanceA = 2, distanceB = 1;
    char increased = 0;
    dp[3] = 1;
    dp[4] = 3;

    for (i = 5; i <= MAXN; ++i) {

        if (increased) {
            increased = 0;
        } else {
            ++distanceB;
            increased = 1;
        }

        distanceA += distanceB;
        dp[i] = dp[i - 1] + distanceA;
    }
}

int main() {
    optimize_ios();
    int n;
    precalculation();

    while (cin >> n) {
        if (n < 3)
            break;

        cout << dp[n - 1] << "\n";
    }
    return 0;
}