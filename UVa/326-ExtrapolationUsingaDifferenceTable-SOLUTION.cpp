#include <bits/stdc++.h>
#define optimize_ios() ios_base::sync_with_stdio(0);cin.tie(0)
#define MAXN 10
using namespace std;

void makeDifferencesTable(int n, int T[MAXN][MAXN]) {
    int i, j;

    for (j = 1; j < n; ++j) {
        for (i = j; i < n; ++i) {
            T[i][j] = T[i][j-1] - T[i-1][j-1];
        }
    }
}

int extrapolate(int n, int k, int T[MAXN][MAXN]) {
    int i, j;

    makeDifferencesTable(n, T);

    for (i = 0; i < k; ++i) {
        for (j = n - 2; j >= 0; --j) {
            T[n-1][j] += T[n-1][j+1];
        }
    }
    return T[n-1][0];
}

int main() {
    optimize_ios();

    int n, k, i;
    int T[MAXN][MAXN];

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
