#include <bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 500002
#define MOD 1000000007
#define ver(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int lli;

int N;
lli A[2][MAXN];
lli Suma;
lli ans;

int main(){
    optimize
    int i, j, k;
    cin>>N;
    for( i = 0; i < N; ++i ){
        cin>>A[0][i]>>A[1][i];
    }
    for( k = 0; k < 2; ++k ){
        sort(A[k], A[k]+N);
        for( i = 1; i < N; ++i ){
            Suma = Suma + A[k][i];
        }
        j = N-1;
        for( i = 0; i < N-1; ++i ){
            ans = ( ans + ( Suma - ( A[k][i] * j ) ) ) % MOD;
            ans %= MOD;
            Suma -= A[k][i+1];
            --j;
        }
    }
    ans %= MOD;
    cout<<(ans%MOD)<<"\n";
    return 0;
}
