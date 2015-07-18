#include <stdio.h>
#include <string.h>
#define MAXN 1000002
#define INF -1

typedef struct Par {
    int y, x;
} Par;

int N;
Par Pila[MAXN]; int p = 0;
int ans[MAXN];

int main(){
    int i, x;
    scanf("%d", &N);
    memset(ans, INF, sizeof(ans));
    scanf("%d", &x);
    Pila[ p ].x = x;
    Pila[p++].y = 0;
    for(i=1; i<N; ++i){
        scanf("%d", &x);
        while( x > Pila[p-1].x && p > 0 ){
            ans[Pila[p-1].y] = i+1;
            --p;
        }
        Pila[ p ].x = x;
        Pila[p++].y = i;
    }
    for(i=0; i<N; ++i){
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
