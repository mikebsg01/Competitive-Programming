#include <bits/stdc++.h>
#define MAXN 1005
#define MOD 1000000007
using namespace std;
typedef long long int lli;

int N, K;
lli A[MAXN];
lli S;
lli ans;

lli exp(lli a, lli b, lli c){
    if( b == 0 )
        return 1;
    lli dev = exp(a, b>>1, c);
    dev = (dev*dev)%c;
    if( b&1 ) dev = (dev*a)%c;
    return dev;
}

int main(){
    int i, j;
    lli x;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>K;
    for(i=0; i<N; ++i){
        cin>>x;
        S += x;
    }
    ans = ( S *  exp(N-1, K, MOD) ) % MOD;
    cout<<ans<<"\n";
    return 0;
}
