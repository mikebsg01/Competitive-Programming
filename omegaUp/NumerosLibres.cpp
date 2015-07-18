#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long int a, b;
long long int m = 0, d=0;

long long int mcd(long long int a, long long int b){
     long long int t;
     while (a > 0){
         t = a;
         a = b % a;
         b = t;
     }
     return b;
 }
 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&a, &b);
		if(mcd(max(a,b), min(b,a))==1) printf("SI\n");
		else printf("NO\n");
	}
	return 0;
}