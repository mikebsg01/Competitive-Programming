#include <bits/stdc++.h>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
#define MAXN 10000002
using namespace std;

int N;
int BIT[MAXN];

void update(int idx, int val) {
    while(idx<=MAXN){
        BIT[idx] += val;
        idx += (idx&(-idx));
    }
}

int query(int idx){
    int s = 0;
    while( idx ){
        s += BIT[idx];
        idx -= (idx&(-idx));
    }
    return s;
}

int main() {
    optimize_ios(0);
    int i, j, x, y, a, b, m, q, _maxY = 0, _minY = 9999999;
    cin>>N;
    for(i=0; i<N; ++i) {
        cin>>x>>y;
        if( x == 1 ) {
            update(y, 1);
            _maxY = max(_maxY, y);
            _minY = min(_minY, y);
        } else {
            a = _minY;
            b = _maxY;
            while( a < b ){
                m = (a+b)/2;
                q = query(m);
                if( q >= y ) {
                    b = m;
                } else {
                    a = m + 1;
                }
            }
            cout<<a<<" "<<query(a)<<"\n";
        }
    }
    return 0;
}
