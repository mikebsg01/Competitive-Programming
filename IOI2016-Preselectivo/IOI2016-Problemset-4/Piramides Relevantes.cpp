#include <iostream>
#include <algorithm>
#define MAXN 1000005
using namespace std;
typedef int lli;

typedef struct Pila {
    lli h, r, maxr;
} Pila;

int N;
lli A[MAXN];
lli h[MAXN], r[MAXN];
Pila pila[MAXN]; int p;
lli ans;

int main(){
    int i,j;
    lli maxr;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(i=1; i<=N; ++i)
        cin>>h[i]>>r[i];
    i = N+1;
    while(--i) {
        maxr = r[i];
        while( h[i] > pila[p].h && p > 0 ) {
            maxr = max(maxr, pila[p].maxr);
            --p;
        }
        if( pila[p].h >= h[i] && p > 0 ) {
            maxr = max(maxr, pila[p].r);
        }
        pila[++p] = { .h = h[i], .r = r[i], .maxr = maxr };
        A[i] = maxr;
    }
    p = 0;
    for(i=1; i<=N; ++i) {
        maxr = r[i];
        while( h[i] > pila[p].h && p > 0 ) {
            maxr = max(maxr, pila[p].maxr);
            --p;
        }
        if( pila[p].h >= h[i] && p > 0 ) {
            maxr = max(maxr, pila[p].r);
        }
        pila[++p] = { .h = h[i], .r = r[i], .maxr = maxr };
        ans = max(maxr, A[i]);
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}
