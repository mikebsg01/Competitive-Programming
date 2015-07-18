#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	int coprimes = 0;
	cin>>n;
	i=n;
	while(i--)
		if(__gcd(i,n) == 1)
			++coprimes;
	cout<<coprimes<<"\n";
	return 0;	
}