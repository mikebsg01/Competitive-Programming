#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int i, tam = 0;
	char sum[1002];
	int array[1002];
	int index = 0;
	scanf("%s",sum);
	tam = strlen(sum);
	for(i=0; i<tam; ++i){
		if( isdigit(sum[i]) ){
			array[index++]= ((int)(sum[i]-'0'));
		}
	}
	sort(array, array+index);
	for(i=0; i<index; ++i){
		printf("%d",array[i]);
		if( (i+1) != index ) printf("+");
	}
	printf("\n");
	return 0;
}