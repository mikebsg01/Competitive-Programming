#include <iostream>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
#define MAXN 505
#define MAXD 10005
using namespace std;
int D; // Capacidad
int N; // Elementos
int P[MAXN], V[MAXN]; // Precio y Volumen
int F[2][MAXD];
int main(){
    optimize_ios(0);
	int i,j,k;
	cin>>D>>N;
	for(i=1; i<=N; ++i){
		cin>>P[i]>>V[i];
	}
	k = 1;
	for(i=1; i<=N; ++i){
		for(j=0; j<=D; ++j){
			if(P[i]<=j){
				F[k][j]=max(F[!k][j], F[!k][j-P[i]]+V[i]);
			} else {
				F[k][j]=F[!k][j];
			}
		}
		k = !k;
	}
	cout<<F[!k][D]<<"\n";
	return 0;
}
