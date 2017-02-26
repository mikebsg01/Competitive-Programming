#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define optimize_ios(x) ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define sz size
#define MAXN 100005
using namespace std;

int N;
vector<int> A[MAXN]; int raiz;
char vis[MAXN];
int limit; char finish;
int ans;

void dfs(int nodo, int nivel) {
    int i;
    if( finish )
        return;
    vis[nodo] = 1;
    if( nodo == 0 ) {
            limit = nivel;
            finish = 1;
            return;
    }
    for(i=0; i<A[nodo].sz(); ++i) {
        if( !vis[A[nodo][i]] )
            dfs( A[nodo][i], nivel + 1 );
    }
}

void dfs2(int nodo, int nivel) {
    int i;
    vis[nodo] = 1;
    if( nivel == limit ) {
        ++ans;
        return;
    }
    for(i=0; i<A[nodo].sz(); ++i) {
        if( !vis[A[nodo][i]] )
            dfs2( A[nodo][i], nivel + 1 );
    }
}

int main() {
    optimize_ios(x);
    int i, x;
    cin>>N;
    for(i=0; i<=N; ++i) {
        cin>>x;
        A[x].pb(i);
        if( x == i )
            raiz = i;
    }
    dfs(raiz, 0);
    memset(vis, 0, sizeof(vis));
    dfs2(raiz, 0);
    --ans;
    cout<<ans<<"\n";
    return 0;
}
