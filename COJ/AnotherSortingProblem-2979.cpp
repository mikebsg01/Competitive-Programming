#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sz size
using namespace std;
typedef vector<pair<int, int> > Vector;

int t,N;
Vector A;

void print(Vector A){
	int i;
	for(i=0; i<A.sz(); ++i){
		cout<<A[i].X<<" "<<A[i].Y<<endl;
	}
	cout<<endl;
}

int maximun(int a, int b, int x){
	int i;
	int max = x;
	int id = a-1;
	for(i=a; i<b; ++i){
		if(A[i].Y<max){
			max = A[i].Y;
			id = i;
		}
	}
	return id;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,k,p;
	int val = 0;
	int next = 0;
	int changes = 0;
	int answer = 0;
	int vis[52];
	cin>>t;
	while( t-- ){
		cin>>N;
		memset(vis, 0, sizeof(vis));
		A.clear();
		answer = 0;
		for(i=0; i<N; ++i){
			cin>>val;
			A.PB(MP(val, i));
		}
		sort(A.begin(), A.end());
		for(i=0; i<N; ++i){
			next = maximun(i+1, N, A[i].Y);
			if( next > i ){
				A[next].Y = A[i].Y;
				vis[next]=1;
				++answer;
			}
			else if(vis[i]){
				++answer;
			}
		}
		cout<<answer<<"\n";
	}
	return 0;
}