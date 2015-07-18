#include <stdio.h>
int main(){
	int n,i;
	int answer = 0;
	scanf("%d",&n);
	for(i=n-1; i>0; i-=2){	
		answer += i;
	}
	printf("%d\n",answer);
	return 0;
}
	
