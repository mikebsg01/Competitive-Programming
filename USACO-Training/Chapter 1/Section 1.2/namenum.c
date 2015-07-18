/*
ID: program43
PROG: namenum
LANG: C
*/
#include <stdio.h>
#include <string.h>

int N;
char code[15];

char names[120];

char Dictionary[5001][21];
int Limit = 0;
int printNames = 0;

char matriz[10][3] = { {' ',' ',' '}, {' ',' ',' '}, {'A','B','C'}, {'D','E','F'}, {'G','H','I'},
					   {'J','K','L'}, {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W','X','Y'} };

int at(char c){
	return ((int)(c-'0'));
}

int openDict(){
	int i;
	freopen("dict.txt","rt",stdin);
	for(i=1; !feof(stdin); ++i){
		scanf("%s", Dictionary[i]);
	}
	Limit = i-1;
}

int binary( int inicio, int fin, char *name ){
	int mitad = (inicio+fin)/2;
	if(inicio>=fin){
		if( !(strcmp(Dictionary[inicio],name)) )
			return inicio;
		else
			return -1;
	}

	int val = strcmp(Dictionary[mitad],name);

	if( !(val) )
		return mitad;
	else if( val < 0 )
		return binary(mitad+1, fin, name);
	else
		return binary(inicio, mitad-1, name);

}

void buscar(int index){
	if(index<N){
		int i;
		int conjunto = at(code[index]);
		for(i=0; i<3; ++i){
			names[index] = matriz[conjunto][i];
			buscar(index+1);
		}
	} else {
		names[index] = '\0';
		if(binary(1,Limit, names) != -1){
			printf("%s\n", names);
			++printNames;
		}
	}

}

int main(){
	int i;
	freopen("namenum.in", "rt", stdin);
	freopen("namenum.out", "wt", stdout);
	scanf("%s",code);
	openDict();
	N = strlen(code);
	buscar(0);
	if(!printNames)
		printf("NONE\n");
	return 0;
}