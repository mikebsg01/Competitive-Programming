#include <bits/stdc++.h>
#define MAXN 2005
#define MAXG 1005
#define INF -1
using namespace std;

int M, N;
char T[MAXN][MAXN];
short X[MAXN*MAXN], Y[MAXN*MAXN]; int p;

short mov[2][4] = { { -1, 0, 1, 0 }, { 0, 1, 0, -1 } };

int bfs(){
	int ans = INF;
	int a, b, i; int x, y, xt, yt;
	int inic = 0, fin = p;
	while( inic != fin ) {
		a = inic; b = fin;
		++ans;
		while( a != b ) {
			y = Y[a]; x = X[a++];	
			for( i = 0; i < 4; ++i ) {
				yt = y + mov[0][i];
				xt = x + mov[1][i];
				if( yt<0 || xt<0 || yt>=M || xt>=N ) continue;
				if( T[yt][xt] == '#' ) continue;
				if( T[yt][xt] == '.' ) {
					T[yt][xt] = 0;
					Y[fin] = yt;
					X[fin++] = xt;
				}
			}
		}
		inic = a;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	cin >> M >> N;
	for( i = 0; i < M; ++i ) {
		for( j = 0; j < N; ++j ) {
			cin >> T[i][j];
			if( T[i][j] == 'G' ) {
				Y[p] = i; 
				X[p++] = j;
			}
		}
	}
	cout<<bfs()<<endl;
	return 0;
}