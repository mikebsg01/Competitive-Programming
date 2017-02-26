#include <bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 52
using namespace std;

int N;
int A[MAXN];
int ans[2];
int main(){
    optimize
    int i, j, bit;
    char c;
    string S;
    cin>>N;
    cin>>S;
    for( i = 0; i < S.size(); ++i ){
        c = S[i];
        if( c == 'W' ){
            A[i] = 1;
        }
    }
    for( i = 0; i < 2; ++i ){
        bit = i;
        for( j = 0; j < N; ++j ){
            if( bit != A[j] ){
                ++ans[i];
            }
            bit = !bit;
        }
    }
    cout<<min(ans[0], ans[1])<<"\n";
    return 0;
}
