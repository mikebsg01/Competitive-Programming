#include <iostream>
using namespace std;
int main(){
	long long int n = 0;
	cin>>n;
	if(n>=0)
		cout<< (n*(n+1))/2) <<"\n";
	else
		cout<< (-(n*(n-1))/2)+1 <<"\n";

	return 0;
}