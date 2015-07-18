#include <bits/stdc++.h>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
#define MAXN 503
#define MAXM 1000003
using namespace std;

typedef struct Par {
    int y, x;
} Par;

int N;
int M[MAXN][MAXN];
int MAYOR;
int MITAD;

Par Cola[MAXM]; int inic, fin;
char vis[MAXN][MAXN];
short mov[2][4] = {{-1,0,1,0},{0,1,0,-1}};

int bfs(int y, int x, int dif){
    int ans = 0;
    int i, j;
    int yt, xt;
    inic = fin = 0;
    Cola[ fin ].y = y;
    Cola[fin++].x = x;
    vis[y][x] = 1;
    while( inic != fin ){
        y = Cola[ inic ].y;
        x = Cola[inic++].x;
        ++ans;
        for( i = 0; i < 4; ++i ){
            yt = y + mov[0][i];
            xt = x + mov[1][i];
            if( yt<1 || xt<1 || yt > N || xt>N ) continue;
            if( !vis[yt][xt] && ( abs( M[y][x] - M[yt][xt] )  ) <= dif ){
                vis[yt][xt] = 1;
                Cola[ fin ].y = yt;
                Cola[fin++].x = xt;
            }
        }
    }
    return ans;
}

int binary(int a, int b){
    int i, j;
    int m, res, mejor;
    while( a < b ){
        m  = (a+b)/2;
        mejor = 0;
        for(i=1; i<=N; ++i)
            memset(vis, 0, sizeof(vis));
        for(i=1; i<=N; ++i){
            for(j=1; j<=N; ++j){
                if( !vis[i][j] ){
                    res = bfs(i, j, m);
                    mejor = max(res, mejor);
                }
            }
        }
        if( mejor >= MITAD ){
            b = m;
        } else {
            a = m + 1;
        }
    }
    return (a+b)/2;
}

int main(){
    int i, j;
    optimize_ios(0);
    cin>>N;
    MITAD = (N*N)/2;
    if( (N*N)%2 ){
        ++MITAD;
    }
    for(i=1; i<=N; ++i){
        for(j=1; j<=N; ++j){
            cin>>M[i][j];
            MAYOR = max(MAYOR, M[i][j]);
        }
    }
    cout<<binary(0, MAYOR)<<"\n";
    return 0;
}
