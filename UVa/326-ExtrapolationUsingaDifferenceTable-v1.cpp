#include <bits/stdc++.h>
#define optimize_ios() ios_base::sync_with_stdio(0);cin.tie(0)
#define MAXN 10
using namespace std;
typedef long long int lli;

void makeDifferencesTable(int n, lli T[MAXN][MAXN]) {
    int i, j;

    for (j = 1; j < n; ++j) {
        for (i = j; i < n; ++i) {
            T[i][j] = T[i][j-1] - T[i-1][j-1];
        }
    }
}

lli factorial(lli num) {
    if (num == 0)
        return 1;

    lli i = num - 1;

    while (i >= 2) {
        num *= i;
        --i;
    }
    return num;
}

lli extrapolate(int n, int k, lli T[MAXN][MAXN]) {
    int i;
    lli ans = 0;

    k = k - 1;

    for (i = k; i < n + k; ++i) {
        ans += T[n-1][i - k] * (factorial(i) / (factorial(k) * factorial(i - k)));
    }
    return ans;
}

int main() {
    optimize_ios();

    int n, k, i;
    lli T[MAXN][MAXN];

    while (cin >> n && n != 0) {
        for (i = 0; i < n; ++i) {
            cin >> T[i][0];
        }

        cin >> k;
        makeDifferencesTable(n, T);
        cout << "Term " << (n + k) << " of the sequence is " << extrapolate(n, k, T) << "\n";
    }
    return 0;
}
