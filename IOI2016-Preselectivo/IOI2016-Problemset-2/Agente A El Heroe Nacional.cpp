#include <iostream>
#include <algorithm>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x);
using namespace std;
typedef long long int lli;

int N;
lli T;
lli ans;

int main(){
    optimize_ios(0);
    int i, j;
    int a, b; 
    int _min;
    cin>>N>>T;
    for(i=0; i<N; ++i){
        cin>>a>>b;
        _min = min(a, b);
        ans += _min / __gcd(a, b);
        if( a != b ) {
            ++ans;
        }
    }
    --ans;
    if( ans < T ) 
        cout<<ans<<"\n";
    else 
        cout<<"El Agente A no sera heroe nacional, el Doctor B destruira su pais\n";
    return 0;
}