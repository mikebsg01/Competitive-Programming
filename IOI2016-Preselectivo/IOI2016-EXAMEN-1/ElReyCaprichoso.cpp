#include <bits/stdc++.h>
#define MAXN 130005
#define MAXA 1000005
using namespace std;
typedef long long int lli;

int N;
int A[MAXN]; int p;
char C[MAXA];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int i, j;
    lli _max = 0, mcm = 0, x;
    cin>>N;
    for(i=0; i<N; ++i){
        cin>>x;
        C[x] = 1;
        _max = max(_max, x);
    }
    for(i=1; i<=_max; ++i){
        if( C[i] ) {
            A[p++] = i;
        }
    }
    _max = 0;
    for(i=0; i<p; ++i){
        for(j=i+1; j<p; ++j){
            mcm = ( A[i] * A[j] ) / __gcd(A[i], A[j]);
            _max = max(_max, mcm);
        }
    }
    cout<<mcm<<"\n";
    return 0;
}
