#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long int lli;

int Q, N;
lli A[MAXN];
lli G;

void binary( lli G ){
    int a, b, m;
    lli res = 0;
    a = 1;
    b = N;
    while( a <= b ) {
        m = (a+b)/2;
        if( A[m] > G ) {
            b = m - 1;
        } else {
            a = m + 1;
        }
    }
    m = (a+b)/2;
    res = G - A[m];
    cout<<m<<" "<<res<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int i, j, x, prev = 0;
    cin>>Q>>N;
    for(i=1; i<=N; ++i){
        cin>>x;
        A[i] = prev + x;
        prev = A[i];
    }
    for(i=1; i<=Q; ++i){
        cin>>G;
        binary(G);
    }
    return 0;
}
