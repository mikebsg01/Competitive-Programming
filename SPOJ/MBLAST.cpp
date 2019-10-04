#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define SZ size()
#define MAXN ((int)(2000+3))
#define INF -1
using namespace std;

string A, B;
int K, DP[MAXN][MAXN];

int bottomUp() {
    FOR(int, i, 1, A.SZ + 1) {
        DP[i][0] = i * K;
    }

    FOR(int, i, 1, B.SZ + 1) {
        DP[0][i] = i * K;
    }

    FOR(int, i, 1, A.SZ + 1) {
        FOR(int, j, 1, B.SZ + 1) {
            DP[i][j] = min(
                abs(A[i - 1] - B[j - 1]) + DP[i - 1][j - 1],
                K + min(
                    DP[i - 1][j],
                    DP[i][j - 1]
                )
            );
        }
    }

    return DP[A.SZ][B.SZ];
}

int main() {
    optimize_io
    cin >> A >> B >> K;
    cout << bottomUp() << '\n';
    return 0;
}