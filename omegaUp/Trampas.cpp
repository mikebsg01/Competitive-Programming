#include <bits/stdc++.h>
#define X first
#define Y second
#define sz size
#define PB push_back
#define MP make_pair
#define INF 90001
using namespace std;
typedef pair<int, pair<int,int> > node;

int N,M;
char m[302][302];

int mov[2][4] = {{-1,0,1,0}, {0,1,0,-1}};

set<node> mon;

void printMap(int y, int x){
	int i,j;
	cout<<"Map: \n";
	for(i=1; i<=N; ++i){
		for(j=1; j<=M; ++j){
			if(i==y and j==x)
				cout<<"P ";
			else
				cout<<m[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

int bfs(int Y, int X){
	int i;
	node a;
	int inicio = 0, fin = 0;
	int y = 0, x = 0, t = 0;
	int yt = 0, xt = 0;
	int vis[302][302]={0};
	vis[Y][X]=1;
	int nx = 0;
	if(m[Y][X]=='x'){
		nx = 1;
	}
	mon.insert( MP(nx, MP( X, Y)) );
	set<node>::iterator it;
	it = mon.begin();
	while(mon.size()){
		it = mon.begin();
		x = (*it).Y.X;
		y = (*it).Y.Y;
		t = (*it).X;
		mon.erase(MP(t,MP(x,y)));
		vis[y][x] = 1;
		if(m[y][x]=='S'){
			return t;
		}
		for(i=0; i<4; ++i){
			yt = y + mov[0][i];
			xt = x + mov[1][i];
			if(yt<1 || yt>N || xt<1 || xt>M){
				continue;
			}
			if(m[yt][xt]=='#'){
				continue;
			}
			if( !vis[yt][xt] ){
				nx = t;
				if(m[yt][xt]=='x'){
					++nx;
				}
				mon.insert( MP(nx, MP(xt, yt) ) );
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int X,Y;
	int i,j;
	cin>>N>>M;
	cin>>Y>>X;
	for(i=1; i<=N; ++i){
		for(j=1; j<=M; ++j){
			cin>>m[i][j];
		}
	}
	cout<<bfs(Y,X)<<"\n";
	return 0;
}