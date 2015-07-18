#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,i;
	int A[102];
	scanf("%d",&n);
	for(i=0; i<n; ++i){
		scanf("%d",&A[i]);
	}
	sort(A, A+n);
	printf("%d\n", (A[0]+A[1]) );
	printf("%d\n", (A[n-1]+A[n-2]) );
	return 0;
}