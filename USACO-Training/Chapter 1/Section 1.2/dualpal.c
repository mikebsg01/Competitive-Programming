/*
ID: program43
PROG: dualpal
LANG: C
*/
#include <stdio.h>
#include <string.h>
int N, S;

char digit[] = {'0','1','2','3','4','5','6','7','8','9'};

int ToBase(int num, int base, char *cadena){
	int i = 0;
	while(num){
		cadena[i] = digit[num%base];
		num /= base;
		++i;
	}
}

int isPalindrome(char *number){
	int i=0;
	int j = strlen(number)-1;
	while(i<=j){
		if(number[i]!=number[j])
			return 0;
		++i;
		--j;
	}
	return 1;
}

int dualpal(int num){
	int i;
	int bases = 0;
	char number[100002];
	for(i=2; i<=10; ++i){
		memset(number, 0, 100002);
		ToBase(num, i, number);
		if(isPalindrome(number)){
			++bases;
		}
		if(bases==2)
			break;
	}

	if(bases==2)
		return 1;
	
	return 0;
}
int main(){
	freopen("dualpal.in", "rt", stdin);
	freopen("dualpal.out", "wt", stdout);
	scanf("%d %d",&N,&S);
	S = S+1;
	while(N){
		if(dualpal(S)){
			printf("%d\n", S);
			--N;
		}
		++S;
	}
	return 0;
}