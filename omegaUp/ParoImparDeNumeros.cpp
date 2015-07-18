#include <iostream>
using namespace std;

int main(){
	int n,i;
	long long int a;
	cin>>n;
	for(i=0; i<n; ++i){
		cin>>a;
		if(a == 0){
			cout<<"cero\n";
		} else {
			if(a%2){
				cout<<"impar ";
				if(a>0){
					cout<<"positivo\n";
				} else {
					cout<<"negativo\n";
				}
			} else {
				cout<<"par ";
				if(a>0){
					cout<<"positivo\n";
				} else {
					cout<<"negativo\n";
				}
			}
		}
	}
	return 0;
}