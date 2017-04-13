#include <bits/stdc++.h>
#define pb push_back
#define MAXN 1000005
#define MAXK 10005
using namespace std;

int N, D, K, M;
int A[MAXK];
int C[MAXN];
int vis[MAXN];
vector<int> V[MAXK]; int p;
int muertes;
int casilla;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i, j, k;
	int q_size, prev, next,suma;
	cin >> N >> D >> K >> M;
	for(i=0; i<K; ++i) {
		cin>>A[i];
		C[A[i]]=1;
	}
	for(i=0; i<K; ++i) {
		if( !vis[A[i]] ) {
			for(j=A[i]; !vis[j]; j = ((j+D)%N) ) {
				vis[j]=1;
				V[p].pb(j);
			}
			++p;
		}
	}
	for(i=0; i<p; ++i) {
		suma = prev = 0;
		next = M;
		for(j=0; j<M; ++j) {
			suma += C[V[i][j]];
		}
		if( suma > muertes ) {
			muertes = suma;
			casilla = V[i][0];
		}
		q_size = V[i].size();
		for(j=1; j<q_size; ++j) {
			suma += C[V[i][next]];
			suma -= C[V[i][prev]];
			if( suma == muertes && V[i][j] < casilla ) {
				casilla = V[i][j];
			}
			else if( suma > muertes) {
				muertes = suma;
				casilla = V[i][j];
			}
			++prev;
			prev %= q_size;
			++next;
			next %= q_size;
		}
	}
	cout<<muertes<<" "<<casilla<<"\n";
	return 0;
}
