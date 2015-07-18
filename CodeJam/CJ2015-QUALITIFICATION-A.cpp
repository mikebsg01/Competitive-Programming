#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1005
using namespace std;

int N,S;
char A[MAXN];

inline int num(char c){
    return ((int)(c-'0'));
}

int main(){
    int i, j, M, tmp_num, dif, up, ans;
    cin>>N;
    for(i=1; i<=N; ++i){
        cin>>S;
        cin>>A;
        ans = up = 0;
        if( S == 0 ){
            cout<<"Case #"<<i<<": "<<0<<"\n";
        } else {
            M = strlen(A);
            for(j=0; j<M; ++j){
                if( j ){
                    tmp_num = num(A[j]);
                    if( up < j && tmp_num > 0 ){
                        dif = j - up;
                        ans += dif;
                        up += dif;
                    }
                    up += num(A[j]);
                } else {
                    up = num(A[j]);
                }
            }
            cout<<"Case #"<<i<<": "<<ans<<"\n";
        }
    }
    return 0;
}
