#include <iostream>
#include <string>
#include <map>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
#define MAXN 1002
using namespace std;

int N;
int M[MAXN][MAXN];
map<string, int> FRIENDS;
int P;

int main(){
    optimize_ios(0);
    int i, j, k;
    string x, y;
    cin >> N;
    for( i = 1; i <= N; ++i ){
        cin >> x;
        FRIENDS[x] = i;
    }
    for( i = 1; i <= N; ++i ){
        for( j = 1; j <= N; ++j ){
            cin >> M[i][j];
        }
    }
    cin>>P;
    for( k=0; k < P; ++k ){
        cin>>x>>y;
        i = FRIENDS[x];
        j = FRIENDS[y];
        cout << M[i][j] << "\n";
    }
    return 0;
}
