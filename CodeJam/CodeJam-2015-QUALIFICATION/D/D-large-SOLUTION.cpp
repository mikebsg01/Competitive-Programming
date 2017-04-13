#include <iostream>
#include <cstdio>
#include <queue>
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 1005
using namespace std;

int T, N;
int ans;

int main(){
    optimize
    int i, j, k, l, r, a, b;
    int X, R, C;
    //freopen("D-large.in","rt",stdin);
    //freopen("D-large.out","wt",stdout);
    cin>>N;
    for(i=1; i<=N; ++i){
        cin>>X>>R>>C;
        if( X == 1 ){
            cout<<"Case #"<<i<<": GABRIEL\n";
        }
        else {
            a = X-(X/2);
            b = X;
            if( ( (R>=a && C>=b) || (R>=b && C>=a) ) && ((R*C)%X) == 0 ){
                cout<<"Case #"<<i<<": GABRIEL\n";
            } else {
                cout<<"Case #"<<i<<": RICHARD\n";
            }
        }
    }
    return 0;
}
