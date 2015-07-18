#include <iostream>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
#define MAXN 205
#define MAXK 1000000
using namespace std;

int N, M, K;
int T[MAXN][MAXN];
int mov[5];

int main(){
    optimize_ios(0);
    int i, j, k, y, x, op;
    int X[3], Y[3];
    int _N, _M;
    cin>>N>>M>>K;
    y = N * MAXK;
    x = M * MAXK;
    for(i=0; i<K; ++i){
        cin>>op;
        ++mov[op];
    }
    y += mov[1] - mov[2];
    x += mov[3] - mov[4];
    y %= N;
    x %= M;
    for(i=0; i<N; ++i){
        for(j=0; j<M; ++j){
            cin>>T[i][j];
        }
    }
    Y[0] = 0; X[0] = M;
    Y[1] = N; X[1] = 0;
    Y[2] = N; X[2] = M;
    for(k=0; k<3; ++k){
        _N = Y[k] + N;
        _M = X[k] + M;
        for(i=Y[k]; i<_N; ++i){
            for(j=X[k]; j<_M; ++j){
                T[i][j] = T[i-Y[k]][j-X[k]];
            }
        }
    }
    _N = y + N;
    _M = x + M;
    for(i=y; i<_N; ++i){
        for(j=x; j<_M; ++j){
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
