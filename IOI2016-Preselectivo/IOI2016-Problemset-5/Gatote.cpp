#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXJ 100005
#define pb push_back
#define mp make_pair
#define sz size
#define X first
#define Y second
#define INF -1
using namespace std;
typedef pair<int, int> Pair;

int P;
int J, L;
vector<Pair> A[2];
vector<Pair>::iterator it;
char vis[MAXJ];
int win[2];

int lower(int idx, int a, int b, int x) {
    int n = b + 1;
    int m;
    while( a <= b ) {
        m = (a+b)/2;
        if( A[idx][m].X == x ) {
            if( A[idx][m-1].X != x || m == 0 ) {
                return m;
            } else {
                b = m - 1;
            }
        }
        else if( A[idx][m].X > x ) {
            b = m - 1;
        } else {
            a = m + 1;
        }
    }
    m = (a+b)/2;
    if( A[idx][m].X == x ) {
        return m;
    } else {
        return n;
    }
}

int upper(int idx, int a, int b, int x) {
    int limit = b;
    int n = a - 1;
    int m;
    while( a <= b ) {
        m = (a+b)/2;
        if( A[idx][m].X == x ) {
            if( A[idx][m+1].X != x || m == limit ) {
                return m+1;
            } else {
                a = m + 1;
            }
        }
        else if( A[idx][m].X > x ) {
            b = m - 1;
        } else {
            a = m + 1;
        }
    }
    m = (a+b)/2;
    if( A[idx][m].X == x ) {
        return m;
    } else {
        return n;
    }
}

int binary(int idx, int a, int b, int x) {
    if( a > b )
        return INF;
    int m;
    while( a <= b ) {
        m = (a+b)/2;
        if( A[idx][m].Y == x ) {
            return m;
        }
        else if( A[idx][m].Y > x ) {
            b = m - 1;
        } else {
            a = m + 1;
        }
    }
    m = (a+b)/2;
    if( A[idx][m].Y == x ) {
        return m;
    } else {
        return INF;
    }
}

void dfs1( int idx, int izq, int der, int x, int y, int linea ) {
    if( linea >= L ) {
        win[!idx] = 1;
        return;
    }
    int a, b, res, i;
    a = lower(idx, izq, der, x);
    b = upper(idx, izq, der, x);
    res = binary(idx, a, b-1, y);
    if( res != INF ) {
        vis[res] = 1;
        dfs1( idx, res+1, der, x+1, y-1, linea+1 );
    }
}

void dfs2( int idx, int izq, int der, int x, int y, int linea ) {
    if( linea >= L ) {
        win[!idx] = 1;
        return;
    }
    int a, b, res, i;
    a = lower(idx, izq, der, x);
    b = upper(idx, izq, der, x);
    res = binary(idx, a, b-1, y);
    if( res != INF ) {
        vis[res] = 1;
        dfs2( idx, res+1, der, x+1, y+1, linea+1 );
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x, y;
    int i, j, k, l, tmp, a, b;
    int line, distX, distY, op;
    cin>>P;
    for(i=1; i<=P; ++i){
        cin>>J>>L;
        for(j=1; j<=J; ++j) {
            cin>>x>>y;
            k = j % 2;
            A[k].pb(mp(x, y));
        }
        win[0] = win[1] = 0;
        for(j=1; j>=0; --j) {
            for(l=0; l<2; ++l) {
                line = 1;
                op = 0;
                if( A[j].sz() >= L && line == L ) {
                    win[!j] = 1;
                }
                sort(A[j].begin(), A[j].end());
                for(k=1; k<A[j].sz(); ++k) {
                    distX = A[j][k].X - A[j][k-1].X;
                    distY = A[j][k].Y - A[j][k-1].Y;
                    if( op == 1 && distX == 0 && distY == 1  ) {
                        ++line;
                    }
                    else if( op == 2 && distX == 1 && distY == 0 ) {
                        ++line;
                    }
                    else if( op == 3 && distX == 1 && distY == 1 ) {
                        ++line;
                    } else {
                        if( distX == 0 && distY == 1 ) {
                            op = 1;
                            line = 2;
                        }
                        else if( distX == 1 && distY == 0 ) {
                            op = 2;
                            line = 2;
                        }
                        else if( distX == 1 && distY == 1 ) {
                            op = 3;
                            line = 2;
                        } else {
                            op = 0;
                            line = 1;
                        }
                    }
                    if( line == L ) {
                        win[!j] = 1;
                    }
                }
                for(k=0; k<A[j].sz(); ++k) {
                    tmp = A[j][k].X;
                    A[j][k].X = A[j][k].Y;
                    A[j][k].Y = tmp;
                }
            }
            sort(A[j].begin(), A[j].end());
            for(k=0; k<A[j].sz(); ++k) {
                if( !vis[k] ) {
                    vis[k] = 1;
                    dfs1( j, k+1, A[j].sz()-1, A[j][k].X + 1, A[j][k].Y - 1, 1 );
                }
            }
            memset(vis, 0, sizeof(vis));
            for(k=0; k<A[j].sz(); ++k) {
                tmp = A[j][k].X;
                A[j][k].X = A[j][k].Y;
                A[j][k].Y = tmp;
            }
            sort(A[j].begin(), A[j].end());
            for(k=0; k<A[j].sz(); ++k) {
                if( !vis[k] ) {
                    vis[k] = 1;
                    dfs2( j, k+1, A[j].sz()-1, A[j][k].X + 1, A[j][k].Y + 1, 1 );
                }
            }
            memset(vis, 0, sizeof(vis));
        }
        if( win[0] && win[1] ) {
            cout<<"-1\n";
        }
        else if( win[0] ) {
            cout<<"1\n";
        }
        else if( win[1] ) {
            cout<<"2\n";
        } else {
            cout<<"0\n";
        }
        A[0].clear(); A[1].clear();
    }
    return 0;
}
