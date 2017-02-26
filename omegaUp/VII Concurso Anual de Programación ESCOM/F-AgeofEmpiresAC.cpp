#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const double PI = 3.14159265359;

int N;
double x[MAXN], y[MAXN];
double area[2];

int main(){
    int i, j;
    double ang;
    double _x, _y, tmp;
    double Xi = 9999999, Xf = 0;
    double Yi = 9999999, Yf = 0;
    scanf("%d", &N);
    for(i=0; i<N; ++i){
        scanf("%lf %lf", &x[i], &y[i]);
        Xi = min(Xi, x[i]); Xf = max(Xf, x[i]);
        Yi = min(Yi, y[i]); Yf = max(Yf, y[i]);
    }
    area[0] = area[1] = ( Xf - Xi ) * ( Yf - Yi );
    for(i=1; i<=90000; ++i){
        ang = (double) 0.001;
        Xi = Yi = 9999999;
        Xf = Yf = 0;
        for(j=0; j<N; ++j){
            _x = ( ( x[j] ) * cos(ang * PI / 180) ) - ( ( y[j] ) * sin(ang * PI / 180) );
            _y = ( ( x[j] ) * sin(ang * PI / 180) ) + ( ( y[j] ) * cos(ang * PI / 180) );
            x[j] = _x;
            y[j] = _y;
            Xi = min(Xi, x[j]); Xf = max(Xf, x[j]);
            Yi = min(Yi, y[j]); Yf = max(Yf, y[j]);
        }
        area[1] = min(area[1], ( Xf - Xi ) * ( Yf - Yi ));
    }
    printf("%.3lf %.3lf\n", area[0], area[1]);
    return 0;
}
