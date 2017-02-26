#include <cstdio>
#define MAXN 66000
typedef int lli;
using namespace std;

lli array[MAXN], dest[MAXN];

void mezclar(lli* A, lli* B, lli* C, int NA, int NB){
	int a=0, b=0, c=0;
	while(a<NA || b<NB){ 
		if(a<NA && b<NB)	
			if(A[a]==B[b])
				C[c++] = A[a++];		
			else if(A[a]<B[b])
				C[c++] = A[a++];
			else
				C[c++] = B[b++];
		else if(a<NA)
			C[c++] = A[a++];
		else
			C[c++] = B[b++];
	}

}
void ordenMezcla(lli* S, lli* Dest, int inicio, int fin){
	lli piv, i;	
	if(inicio>=fin)
		return;
	piv = (inicio+fin)/2;
	for(i=inicio; i<=fin; i++)
		Dest[i] = S[i];
	ordenMezcla(Dest, S, inicio, piv);
	ordenMezcla(Dest, S, piv+1, fin);
	int lim_inf = piv+1, lim_sup = fin, temp = 0;
	while(lim_inf<=lim_sup){
		temp = S[lim_inf];
		S[lim_inf] = S[lim_sup];
		S[lim_sup] = temp;
		++lim_inf;
		--lim_sup;
	}
	mezclar(&S[inicio], &S[piv+1], &Dest[inicio], piv-inicio+1, fin-piv);
}

int main(){
	int n, i;
	scanf("%d",&n);
        if( n > 1 ){
      	for(i=0; i<n; ++i)			            
           scanf("%d",&array[i]);
        ordenMezcla(array, dest, 0, n-1);
		for(int i=0; i<n; ++i){
			printf("%d ",dest[i]);
		}
		printf("\n");
        } else if( n == 1 ) {
             int num; 
             scanf("%d", &num);
             printf("%d\n", num);
        }
	return 0;
}
