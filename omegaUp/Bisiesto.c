#include <stdio.h>

int main(){
	int n,i,num;
	scanf("%d",&n);
	for(i=0; i<n; ++i){
		scanf("%d",&num);
		if( !(num%4) || !(num%400) ){
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}
