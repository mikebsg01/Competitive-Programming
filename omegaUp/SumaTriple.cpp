#include <iostream>
using namespace std;
typedef long long int lli;

int main(){
	ios_base::sync_with_stdio(0);
	lli f[65];
	int n,i;
	cin>>n;
	f[1] = 1;
	f[2] = 1;
	f[3] = 2;
	for(i=4; i<=n; ++i){
		f[i] = f[i-3]+f[i-2]+f[i-1];
	}
	for(i=1; i<=n; ++i){
		cout<<f[i]<<" ";
	}
	cout<<"\n";
	return 0;
}