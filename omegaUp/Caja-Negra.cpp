#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,i,j;
	char A[32];
	int vis[32]={0};
	pair<int, char> P[32];
	int p = 0;
	scanf("%d",&n);
	scanf("%s",A);
	for(i=0; i<n; ++i){
		if(!vis[i]){
			vis[i] = 1;
			P[p].first = 1;
			P[p].second = A[i];
			for(j=0; j<n; ++j){
				if(!vis[j]){
					if(A[i]==A[j]){
						vis[j] = 1;
						++P[p].first;
					}		
				}
			}
			++p;
		}
	}
	sort(P,P+p);
	printf("%c",P[p-1].second);
	return 0;
}
