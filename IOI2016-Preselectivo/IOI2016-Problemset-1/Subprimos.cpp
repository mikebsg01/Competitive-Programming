#include <iostream>
#include <vector>
#define optimize ios_base::sync_with_stdio(0);
#define MAXSIZE 100000
#define pb push_back
#define sz size
using namespace std;

vector<int> V;

void criba( bool* m, int tam ) {
    int i, h;
    m[0] = m[1] = false;
    for( i = 2; i <= tam; ++i )
        m[i] = true;
    for( i = 2; i * i <= tam; ++i ) {
        if( m[i] ) {
            for( h = 2; i*h <= tam; ++h ){
                m[i*h] = false;
            }
        }
    }
}

int divisores(int num){
    int div = 0, idx = 0, j;
    j = V[idx];

    while( num%j == 0 ){
        num /= j;
        ++div;
    }
    j = V[++idx];
    while( num > 1 ) {
        while( num%j == 0 ){
            num /= j;
            ++div;
        }
        j = V[++idx];
    }
    return div;
}

int main(){
    optimize
    int A, B;
    bool m[MAXSIZE];
    int ans = 0;
    int i, div;
    cin>>A>>B;
    criba(m, max(A, B));
    for( i = 2; i <= 100000; ++i )
        if( m[i] ) {
            V.pb(i);
        }
    for( i = A; i <= B; ++i )
        if( !m[i] ){
            div = divisores(i);
            if( m[div] )
                ++ans;
        }
    cout << ans << "\n";
    return 0;
}
