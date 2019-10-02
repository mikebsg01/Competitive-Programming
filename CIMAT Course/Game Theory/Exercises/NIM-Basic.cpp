#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

bool DP[MAXN + 2];

int main() {
    DP[1] = 1;
    DP[2] = 0;
    DP[3] = 1;
    DP[4] = 0;
    DP[5] = 1;
    DP[6] = 0;
    DP[7] = 1;
    DP[8] = 1;

    for (int i = 9; i <= MAXN; ++i) {
        DP[i] = !DP[i - 1] or !DP[i - 3] or !DP[i - 8];
    }

    for (int i = 1; i <= MAXN; ++i) {
        if (! DP[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}