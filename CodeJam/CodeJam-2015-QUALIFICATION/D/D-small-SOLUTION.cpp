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
    freopen("D-small-attempt8.in","rt",stdin);
    freopen("D-small-attempt8.out","wt",stdout);
    cin>>N;
    for(i=1; i<=N; ++i){
        cin>>X>>R>>C;
        if( X == 1 ){
            cout<<"Case #"<<i<<": GABRIEL\n";
        }
        else if( X == 2 ){
            if( ((R*C)%X) == 0 ){
                cout<<"Case #"<<i<<": GABRIEL\n";
            } else {
                cout<<"Case #"<<i<<": RICHARD\n";
            }
        }
        else if( X == 3 ){
            if( (R==2 && C==3) || (C==2 && R==3) || (R==3 && C==3) || (R==4 && C==3) || (R==3 && C==4) ){
                cout<<"Case #"<<i<<": GABRIEL\n";
            } else {
                cout<<"Case #"<<i<<": RICHARD\n";
            }
        } else if( X == 4 ) {
            if( (R == X && C == X) || (R==3 && C==4) || (R==4 && C==3) ){
                cout<<"Case #"<<i<<": GABRIEL\n";
            } else {
                cout<<"Case #"<<i<<": RICHARD\n";
            }
        }
    }
    return 0;
}
