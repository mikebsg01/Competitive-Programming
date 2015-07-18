#include <bits/stdc++.h>
#define MAXK 11
#define MAXN 1005
#define INF MAXN*MAXN
using namespace std;

typedef struct Cola {
    int x, y, t;
} Cola;

int N, M, K;
int Xi, Yi;
int Xf, Yf;
int X[MAXK], Y[MAXK];
Cola cola[MAXN*MAXN]; int inic, fin;
char vis[MAXN][MAXN];
int ans = INF;

void bfs(int x, int y, int t){
    int i, j, yt, xt;
    inic = fin = 0;
    cola[ fin ].t = 0;
    cola[ fin ].y = y;
    cola[fin++].x = x;
    vis[x][y] = 1;
    while( inic != fin ) {
        t = cola[ inic ].t;
        y = cola[ inic ].y;
        x = cola[inic++].x;
        if( y == Yf && x == Xf ){
            ans = min(ans, t);
            continue;
        }
        for( i = 0 ; i < K; ++i ){
            yt = y + Y[i];
            xt = x + X[i];
            if( yt<1 || xt<1 || yt>M || xt>N ) continue;
            if( !vis[xt][yt] ){
                vis[xt][yt] = 1;
                cola[ fin ].t = t+1;
                cola[ fin ].y = yt;
                cola[fin++].x = xt;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, x, y;
    cin>>N>>M>>K;
    cin>>Xi>>Yi;
    cin>>Xf>>Yf;
    for(i=0; i<K; ++i){
        cin>>X[i]>>Y[i];
    }
    vis[Xi][Yi] = 1;
    bfs(Xi, Yi, 0);
    if( ans != INF ) {
        cout<<ans<<"\n";
    } else {
        cout<<"-1\n";
    }
    return 0;
}
