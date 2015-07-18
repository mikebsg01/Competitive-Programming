#include <cstdio>

int main(){
	int i;
	float num, suma, prom;
	suma = prom = 0;
	for(i=0; i<12; ++i){
		scanf("%f",&num);
		suma += num;
	}
	prom = suma/12;
	printf("$%1.2f\n", prom);
	return 0;
}