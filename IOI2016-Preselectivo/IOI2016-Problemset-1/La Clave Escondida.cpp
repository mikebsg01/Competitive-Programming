#include <bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);
#define sz size
#define MAXN 10002
using namespace std;

int N;
string S;
int A[MAXN];
string ans;

int val(char c){
    if( isupper(c) ){
        return (((int)(c-'A'))+1);
    } else {
        return (((int)(c-'a'))+1);
    }
}

char letra(int n){
    return ((char)((n-1)+'A'));
}

int main(){
    optimize
    freopen("a.in.c","rt",stdin);
    int i, j, P;
    char c;
    for( j = 0; j < 2; ++j ) {
        P = 1;
        memset(A, 0, sizeof(A));
        scanf("%*c%*c%d ", &N);
        i = 0;
        while(isalpha( c = getchar() )){
            if( c == '\n' ) break;
            A[( i % N )] += val( c );
            ++i;
        }
        for( i = 0; i < N; ++i ){
            A[i] %= 10;
            P *= ( A[i] + 1 );
        }
        P %= 10;
        ++P;
        if( j )
            ans += letra(P);
        else {
            ans += ((char)(P+'0'));
            ans += "-";
        }
    }
    cout<<ans<<"\n";
    return 0;
}
