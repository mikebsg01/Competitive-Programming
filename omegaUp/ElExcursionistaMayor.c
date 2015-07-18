#include <stdio.h>
#define max(a,b) a>b?a:b
int main(){
	int n,i;
	int num;
	int ans = 0;
	scanf("%d",&n);
	for(i=0; i<n; ++i){
		scanf("%d",&num);
		ans = max(ans,num);
	}
	printf("%d\n", ans);
	return 0;
}