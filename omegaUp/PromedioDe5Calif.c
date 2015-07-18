#include <stdio.h>

int main(){
	int num,i;
	float sum = 0, prom;
	for(i=0; i<5; ++i){
		scanf("%d",&num);
		sum += num;
	}
	prom = sum/5;
	printf("%1.1f\n",prom);
	return 0;
}