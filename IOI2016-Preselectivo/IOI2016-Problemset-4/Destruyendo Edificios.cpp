#include <iostream>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
#define MAXN 1000002
using namespace std;
typedef long long int lli;

int N;
int V[MAXN];
int A[MAXN];
int Pila[MAXN][2]; int p;
lli ans;

int main(){
    optimize_ios(0);
    int i; lli dist, area;
    cin>>N;
    Pila[p][0] = -1;
    Pila[p++][1] = 0;
    for(i=1; i<=N; ++i){
        cin>>V[i];
        while( Pila[p-1][0] >= V[i] )
            --p;
        A[i] = Pila[p-1][1];
        Pila[p][0] = V[i];
        Pila[p++][1] = i;
    }
    p = 0;
    Pila[p][0] = -1;
    Pila[p++][1] = N+1;
    i = N;
    while(i--){
        while( Pila[p-1][0] >= V[i] )
            --p;
        dist = (lli) Pila[p-1][1] - A[i] - 1;
        area = dist * V[i];
        ans = max(ans, area);
        Pila[p][0] = V[i];
        Pila[p++][1] = i;
    }
    cout<<ans;
    return 0;
}
