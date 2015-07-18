#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#define BASE 1000000000

#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define FOR(i,x,y) for(int i=(int)x; i<(int)y; i++)
#define RFOR(i,x,y) for(int i=(int)x; i>(int)y; i--)
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define IN(a,pos,c) insert(a.begin()+pos,1,c)
#define DEL(a,pos,cant) erase(a.begin()+pos,cant)

#define LON 52
#define MAXN 52
#define CARRY 1000000000

typedef long ulli;

typedef struct {
	ulli iSize, aiBlock[MAXN];
} stBigNum;

ulli iA, iB;

stBigNum tA, tB;

int odd(ulli x){
	return ((x & 0x0001) != 0);
}

void clean_number(stBigNum *ptNum){
	int i,j;
	ptNum->iSize = 1;
	for(i=0; i<MAXN; ++i){
		ptNum->aiBlock[i] = 0;
	}
}

void init_number(stBigNum *ptNum, ulli iK){
	ptNum->iSize = 1;
	memset(ptNum->aiBlock, 0, sizeof(ptNum->aiBlock));
	ptNum->aiBlock[0] = iK;
}

int equal_zero(stBigNum *ptNum){
	int i;
	for(i=ptNum->iSize-1; (ptNum->aiBlock[i]==0) & (i>0); --i);
	return (ptNum->aiBlock[i]==0);
}	

int less_equal(stBigNum *ptNumX, stBigNum *ptNumY);


void shift_r(stBigNum *ptNum){
	int i;
	for(i=ptNum->iSize-1; i>0; --i){
		if(odd(ptNum->aiBlock[i])){
			ptNum->aiBlock[i-1] += CARRY;
		}
		ptNum->aiBlock[i] >>= 1;
	}
	ptNum->aiBlock[0] >>= 1;
	if(ptNum->aiBlock[ptNum->iSize-1] == 0){
		ptNum->iSize--;
	}
}

void shift_l(stBigNum *ptNum){
	int i;
	for(i=ptNum->iSize-1; i>=0; --i){
		ptNum->aiBlock[i] <<= 1;
		if(ptNum->aiBlock[i] >= CARRY){
			ptNum->aiBlock[i+1]++;
			ptNum->aiBlock[i] -= CARRY;
		}
	}
	if(ptNum->aiBlock[ptNum->iSize]!=0){
		ptNum->iSize++;
	}
}

stBigNum add(stBigNum tNumX, stBigNum tNumY){
	int i;
	if(tNumY.iSize > tNumX.iSize){
		tNumX.iSize = tNumY.iSize;
	}
	for(i=0; i<tNumX.iSize; ++i){
		tNumX.aiBlock[i] += tNumY.aiBlock[i];
		if(tNumX.aiBlock[i] >= CARRY) {
			tNumX.aiBlock[i] -= CARRY;
			tNumX.aiBlock[i+1]++;
		}
	}
	if( (tNumX.iSize < MAXN) && ( tNumX.aiBlock[tNumX.iSize] != 0 ) ){
		tNumX.iSize++;
	}
	return (tNumX);
}

stBigNum multiply(stBigNum tNumX, stBigNum tNumY){
	stBigNum tResult;
	clean_number(&tResult);
	while(!equal_zero(&tNumX)){
		if(odd(tNumX.aiBlock[0])){
			tResult = add(tResult, tNumY);
		}
		shift_r(&tNumX);
		shift_l(&tNumY);
	}
	return (tResult);
}

stBigNum power(stBigNum tNumX, ulli iK){
	stBigNum tResult;
	init_number(&tResult, 1);
	while(iK > 0){
		if(odd(iK)){
			tResult = multiply(tResult, tNumX);
		}
		tNumX = multiply(tNumX, tNumX);
		iK >>= 1;
	}
	return (tResult);
}


void read(stBigNum *ptNum){
	int i, iPower = 1;
	char pszString[LON*MAXN];
	scanf("%s",pszString);
	clean_number(ptNum);
	for(i=strlen(pszString)-1; i>=0; i--){
		ptNum->aiBlock[ptNum->iSize-1] += (((int)pszString[i])-48)*iPower;
		iPower *= 10;
		if(iPower == CARRY){
			iPower = 1;
			ptNum->iSize++;
		}
	}
}

void concatr(char *a, char *b){
int i,j;
	j = strlen(a);
	for(i=0; i<strlen(b); ++i){
		if(b[i]>='0' and b[i] <= '9'){
			a[j++] = b[i];
		}
	}
	a[j] = '\0';
}

void write(stBigNum *ptNum){
	int i,j;
	char pszTemp[LON];
	char pszString[LON*MAXN];

	sprintf(pszString, "%ld", ptNum->aiBlock[ptNum->iSize-1]);
	for(i=ptNum->iSize-2; i>=0; --i){
		sprintf(pszTemp, "%*ld", LON, ptNum->aiBlock[i]);
		concatr(pszString, pszTemp);
	}
	printf("%s\n", pszString);
}

int main(){
	int N = 100;
	int i;
	stBigNum a[102],b;
	init_number(&b,0);
	freopen("pruebaBigNumbers.txt","rt",stdin);
	for(i=1; i<=N; ++i){
		read(&a[i]);
		b = add(b,a[i]);
	}
	write(&b);
	return 0;
}