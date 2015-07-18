#include <stdio.h>

int main(){
	int n, i, num, val, pos = 0;
	scanf("%d",&n);
	for(i=0; i<n; ++i){
		scanf("%d",&num);
		if(!i){
			val = num;
		} else {
			if(num<val){
				++pos;
			}
		}	
	}
	printf("%d",pos);
	return 0;
}
