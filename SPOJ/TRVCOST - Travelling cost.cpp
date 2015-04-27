
#include <bits/stdc++.h>
#define MAXN 505
#define INF 9999999
using namespace std;
typedef long long int lli;

int m[MAXN+1][MAXN+1];

int N, U, Q;

void init(){
    int i, j;
    for( i = 0; i < MAXN; ++i ){
        for( j = 0; j < MAXN; ++j ){
            if( i != j ){
                m[i][j] = INF;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, k; int x, y, w; int maxN = 1; int V;
    int ans;
    cin >> N;
    init();
    for( i = 0; i < N; ++i ){
        cin >> x >> y >> w;
        maxN = max( maxN, max( x, y ) );
        m[x][y] = min( m[x][y], w );
        m[y][x] = min( m[y][x], w );
    }
    for( k = 0; k <= maxN; ++k ){
        for( i = 0; i <= maxN; ++i ){
            for( j = 0; j <= maxN; ++j ){
                m[i][j] = min( m[i][j] , m[i][k] + m[k][j] );
            }
        }
    }
    cin >> U;
    cin >> Q;
    for( i = 0; i < Q; ++i ){
        cin >> V;
        ans = min( m[U][V], m[V][U] );
        if( ans == INF ){
            cout << "NO PATH\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
