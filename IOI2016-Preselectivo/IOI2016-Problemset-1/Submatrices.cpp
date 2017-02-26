#include <bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define sz size
#define MAXN 1002
using namespace std;

int R, C;
int n[MAXN][MAXN];
int r, c;
int m[MAXN][MAXN];
int ans[MAXN][MAXN];

typedef struct coord {
    int x[4]; int y[4];
} coord;

vector<coord> A;

int main(){
    optimize
    int i, j, k, l, a;
    coord tmp;
    cin>>R>>C;
    for( i = 0; i < R; ++i ){
        for( j = 0; j < C; ++j ){
            cin>>n[i][j];
        }
    }
    cin>>r>>c;
    for( i = 0; i < r; ++i ){
        for( j = 0; j < c; ++j ){
            cin>>m[i][j];
        }
    }
    int op = 0;
    bool dif = false;
    for( i = 0; i < ( R - r + 1 ); ++i ){
        for( j = 0; j < ( C - c + 1 ); ++j ){
            dif = false;
            for( k = 0; k < r; ++k ){
                for( l = 0; l < c; ++l ){
                    ++op;
                    if( m[k][l] != n[i+k][j+l] ){
                        dif = true;
                        break;
                    }
                }
                if( dif ){
                    break;
                }
            }
            if( !dif ){
                tmp.y[0] = i;      tmp.x[0] = j;
                tmp.y[1] = i;      tmp.x[1] = j+c-1;
                tmp.y[2] = i+r-1;  tmp.x[2] = j;
                tmp.y[3] = i+r-1;  tmp.x[3] = j+c-1;
                A.pb(tmp);
            }
        }
    }
    bool solve = false;
    for( i = 0; i < R; ++i ){
        for( j = 0; j < C; ++j ){
            solve = false;
            for( k = 0; k < A.sz(); ++k ){
                tmp = A[k];
                if( i >= tmp.y[0] && j >= tmp.x[0] &&
                    i >= tmp.y[1] && j <= tmp.x[1] &&
                    i <= tmp.y[2] && j >= tmp.x[2] &&
                    i <= tmp.y[3] && j <= tmp.x[3] ) {
                    solve = true;
                    break;
                }
            }
            if( solve ){
                cout<<"1 ";
            } else {
                cout<<"0 ";
            }
       }
       cout<<"\n";
    }
    return 0;
}
