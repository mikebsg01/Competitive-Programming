#include <bits/stdc++.h>
#define ver(x) cout<<"-> "<<#x<<" "<<x<<"\n";
#define verPar(x, y) cout<<"-> "<<#x<<" "<<x<<" - "<<#y<<" "<<y<<"\n";
#define pres 0.001
#define MAXN 1005
using namespace std;

int N;
double A[MAXN];
double IZQ[3], DER[3], m[3];

inline double posi(double n){
    return ( n < 0 ) ? ( -1 * n ) : n;
}

double binary(double a, double b){
    int i, j;
    double m, suma;
    for( j = 0; j < 25; ++j ) {
        m = (a+b)/2;
        suma = 0;
        for( i = 1; i <= N; ++i ) {
            suma += 1 / ( A[i] - m );
        }
        if( suma > 0 ){
            b = m;
        } else {
            a = m;
        }
    }
    return a;
}

int main(){
    int i, j;
    scanf("%d", &N);
    for(i=1; i<=N; ++i){
        scanf("%lf", &A[i]);
    }
    sort(A+1, A+N+1);
    printf("%d\n", N-1);
    for(i=1; i<N; ++i){
        printf("%.3lf ", binary( A[i], A[i+1] ) );
    }
    printf("\n");
    return 0;
}

