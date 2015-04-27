#include <stdio.h>
#include <string.h>
#define MAXN 100005

typedef struct P {
	int X, Y;
} P;

int N;
char S[MAXN];
P Pila[MAXN]; int p = 0;
P Cola[MAXN]; int q = 0;

int main(){
	int i, j;
	char partial[MAXN];
	P tmp; 
	gets(S);
	N = strlen(S);
	i = 0;
	while( S[i] != '[' && S[i] != ']' && S[i] != '\0' ){
		++i;
	}
	tmp.X = 0; tmp.Y = i;
	// printf("%d %d\n", tmp.X, tmp.Y);
	while( S[i] == '[' || S[i] == ']' ) {
		++i;
	}
	Pila[p++] = tmp;
	while( S[i] != '\0' ){
		j = i;
		while( S[j] != '[' && S[j] != ']' && S[j] != '\0' ){
			++j;
		}
		tmp.X = i; tmp.Y = j;
		while( S[j] == '[' || S[j] == ']' ) {
			++j;
		}
		if( S[i - 1] == '[' ) { 
			Pila[p++] = tmp;
		} else {
			Cola[q++] = tmp;
		}
		i = j;
	}
	--p;
	for( i = p; i >= 0; --i ){
		for( j = Pila[i].X; j < Pila[i].Y; ++j ){
			printf("%c", S[j]);
		}
	}
	for( i = 0; i < q; ++i ) {
		for( j = Cola[i].X; j < Cola[i].Y; ++j ){
			printf("%c", S[j]);
		}
	}
	printf("\n");
	return 0;
}
