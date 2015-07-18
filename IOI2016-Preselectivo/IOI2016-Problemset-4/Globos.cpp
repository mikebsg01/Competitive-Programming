#include <cstdio>
#include <algorithm>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
#define MAXN 200005
using namespace std;

typedef struct Pila {
    double x, r;
} Pila;

int N;
Pila pila[MAXN]; int p;

int main(){
    int i;
    double x, r;
    scanf("%d", &N);
    for( i = 0;  i < N; ++i ) {
        scanf("%lf %lf", &x, &r);
        while( p ) {
            r = min( r , ( ( pila[p].x - x ) * ( pila[p].x - x ) ) / ( 4 * pila[p].r ) );
            if( r < pila[p].r )
                break;
            --p;
        }
        printf("%.6lf ", r);
        pila[++p] = { .x = x, .r = r };
    }
    printf("\n");
    return 0;
}
