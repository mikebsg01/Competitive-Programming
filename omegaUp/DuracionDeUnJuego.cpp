#include <iostream>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<"24\n";
	}
	else if(a>b){
		cout<<( (24-a)+b )<<endl;
	} else {
		cout<<( (b-a) )<<endl;
	}
	return 0;
}