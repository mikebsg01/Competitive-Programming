/*
ID: program43
PROG: palsquare
LANG: C
*/
#include <stdio.h>
#include <string.h>

char number[1002], square[1002];

char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

void toBase(int num, int base, char* cadena){
	int i = 0;
	while(num){
		cadena[i] = digit[num % base];
		num /= base;
		++i;
	}
}

int isPalindrome(char number[]){
	int i = 0;
	int j = strlen(number)-1;
	while(i<=j){
		if(number[i]!=number[j]) 
			return 0;

		++i; --j;
	}
	return 1;
}

void Inverted(char* number){
	char temp;
	int i = 0;
	int j = strlen(number)-1;
	while(i<j){
		temp = number[j];
		number[j] = number[i];
		number[i] = temp;
		++i; --j;
	}
}


int main(){
	freopen("palsquare.in", "rt", stdin);
	freopen("palsquare.out", "wt", stdout);
	int B, N, i;
	scanf("%d",&B);
	for(i=1; i<=300; ++i){
		N = i*i;
		toBase(N,B,square);
		if(isPalindrome(square)){
			toBase(i,B,number);
			Inverted(number);
			printf("%s %s\n", number, square);
		}
	}
	return 0;
}