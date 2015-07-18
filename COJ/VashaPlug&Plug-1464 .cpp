#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T;
char s[10002];
char pila[10002]={0};
int p = 0;
int main(){
	int i,j,k;
	cin>>T;
	for(i=0; i<T; ++i){
		memset(pila, 0, sizeof(pila));
		p = 0;
		cin>>s;
		for(j=0; j<strlen(s); ++j){
			if(!p){
				pila[p++]=s[j];
			} else {
				if(pila[p-1]==s[j]){
					if(p)
						--p;
				} else {
					pila[p++]=s[j];
				}
			}
		}
		pila[p]='\0';
		cout<<pila<<"\n";
	}
	return 0;
}