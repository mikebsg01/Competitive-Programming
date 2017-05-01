#include <bits/stdc++.h>
#define MAXN 100005
#define X first
#define Y second
#define mp make_pair
#define INF -1
using namespace std;
typedef pair<int, int> P;

int N, M;
P A[MAXN]; int p = 0;
int ans = 0;

int binary( int inf, int sup, int sumIzq, int sumDer ) {
    int iA, iB;
    int a, b, m;
    int x = 0;
    a = inf; b = sup;
    while( a <= b ){
        m = (a+b)/2;
        x = ( sumIzq + m );
        iA = x - ( sup - m );
        iB = x + ( sup - m );
        if( sumDer >= iA && sumDer <= iB ){
            a = m + 1;
        } else {
            b = m - 1;
        }
    }
    m = (a+b)/2;
    x = (sumIzq + m );
    iA = x - ( sup - m );
    iB = x + ( sup - m );
    if( sumDer >= iA && sumDer <= iB ){
        return x;
    } else {
        return INF;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int D, H;
    int i, j, b;
    cin>>N>>M;
    for( i = 0; i < M; ++i ) {
        cin>>D>>H;
        A[i] = mp(D, H);
    }
    for( i = 0; i < M - 1; ++i ){
        b = binary( 0 , abs( A[i+1].X - A[i].X ) , A[i].Y, A[i+1].Y );
        ans = max(ans, b);
        if( b == INF ) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    if( M >= 1 ) {
        if( A[M - 1].X < N ) {
            ans = max( ans, A[M - 1].Y + ( N - A[M - 1].X  ) );
        }
        ans = max(ans, ( A[0].Y + ( A[0].X - 1 ) ) );
    }
    cout << ans << "\n";
    return 0;
}