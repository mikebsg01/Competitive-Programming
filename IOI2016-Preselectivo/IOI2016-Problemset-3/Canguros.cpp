#include <stdio.h>
int main(){
	int Cola[2000005], primero=0, ultimo=0, CG=0, C=0, N=0, V=0, i;
	char OP;
	scanf("%d%d%*c",&C, &N);
	while(N--){
		scanf("%c%*c",&OP);
		if(OP=='A'){
			--CG;
			C = C -Cola[primero++] - 1;
		}
		else if(OP=='C'){
			printf("%d\n",CG);
		}
		else if(OP=='N'){ 
			++CG;
			scanf("%d%*c", &Cola[ultimo++]);
		}
		else {
			printf("%d\n", C);
		}
	}
	return 0;
}
