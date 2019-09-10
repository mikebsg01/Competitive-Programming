#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define PB(s,x) s.push_back(x)
#define SZ size()
#define MAXN ((int)(105))
#define MAXM ((int)(5))
#define INF -1
using namespace std;

int N, A[MAXN], DP[MAXN][MAXM];

int main() {
    optimize_io
    int x, a, b, c;
    cin >> N;

    FOR(int, i, 1, N + 1) {
        cin >> A[i];
    }

    FOR(int, i, 1, N + 1) {
        a = DP[i - 1][0],
        b = DP[i - 1][1],
        c = DP[i - 1][2];

        DP[i][0] = max(a, max(b, c));

        if (A[i] == 1 or A[i] == 3) {
            DP[i][1] = 1 + max(a, c);
        }
        
        if (A[i] == 2 or A[i] == 3) {
            DP[i][2] = 1 + max(a, b);
        }
    }
    
    a = DP[N][0];
    b = DP[N][1];
    c = DP[N][2];

    cout << (N - max(a, max(b, c))) << '\n';
    return 0;
}