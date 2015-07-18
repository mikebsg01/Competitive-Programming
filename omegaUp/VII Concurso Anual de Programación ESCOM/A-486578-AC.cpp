#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int N;
char S[MAXN];

int toDecimal(char c){
    if( isdigit(c) ){
        return ((int)(c-'0'));
    } else {
        return ((int)(c-'A'))+10;
    }
}

int main(){
    int i, ascii;
    while( gets(S) ){
        N = strlen(S);
        for(i=0; i<N; i+=2){
            ascii = ( toDecimal(S[i]) * 16 ) + toDecimal( S[i+1] );
            printf("%c",ascii);
        }
        printf("\n");
    }
    return 0;
}
