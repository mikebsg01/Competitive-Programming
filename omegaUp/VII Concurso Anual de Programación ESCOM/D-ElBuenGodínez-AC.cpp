#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define ver(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
#define sz size
#define DIGITS 11
#define MAXN 21
using namespace std;
typedef long long int lli;

int N;
vector<int> A;
vector<int> B;
vector<int>::iterator it;
char S[MAXN];
char vis[MAXN];
char D[DIGITS];
char V[DIGITS];
lli FAC[MAXN];
lli ans = 1;

int toNum(char c){
    return ((int)(c-'0'));
}

int main(){
    int i, j, k, x, l, limit;
    lli p, f, r, result;
    scanf("%s", S);
    N = strlen(S);
    for(i=0; i<N; ++i){
        x = toNum( S[i] );
        A.pb( x );
    }
    FAC[0] = FAC[1] = 1;
    for(k=2; k<=N; ++k){
        FAC[k] = FAC[k-1] * k;
    }
    p = FAC[N];
    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            if( !vis[j] ){
                B.pb( A[j] );
            }
        }
        sort(B.begin(), B.end());
        it = lower_bound(B.begin(), B.end(), A[i]);
        limit = ( it - B.begin() );
        p /= N - i;
        for(j=0; j<limit; ++j){
            if( V[B[j]] ) continue;
            for(k=0; k<B.sz(); ++k){
                if( j != k ){
                    ++D[B[k]];
                }
            }
            r = 1;
            for(k=0; k<=9; ++k){
                if( D[k] ){
                    f = FAC[D[k]];
                    r *= f;
                }
            }
            result = p / r;
            ans += result;
            V[B[j]] = 1;
            memset(D, 0, sizeof(D));
        }
        memset(V, 0, sizeof(V));
        vis[i] = 1;
        B.clear();
    }
    printf("%lld\n", ans);
    return 0;
}
