#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long int lli;
int N, M, W;
lli A[MAXN];
class BIT {
private:
    lli B[MAXN];
public:
    void init(){
        memset(B, 0, sizeof(B));
    }
    void update(int idx, lli val){
        while(idx<=N){
            B[idx] += val;
            idx += idx&(-idx);
        }
    }
    lli query(int idx){
        lli s = 0;
        while(idx){
            s += B[idx];
            idx -= idx&(-idx);
        }
        return s;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    BIT bit;
    lli a, b, m, resto, falta;
    int i;
    cin>>N>>M>>W;
    for(i=1; i<=N; ++i){
        cin>>A[i];
    }
    a = 1, b = 1000100001;
    while(a<b){
        m = (a+b+1)/2;
        bit.init();
        falta = 0;
        for(i=1; i<=N; ++i){
            resto = m - (A[i]+bit.query(i));
            if(resto>0){
                falta += resto;
                bit.update(i, resto); bit.update(i+W, -resto);
            }
        }
        if(falta>M){
            b = m-1;
        } else {
            a = m;
        }
    }
    cout<<a<<"\n";
    return 0;
}