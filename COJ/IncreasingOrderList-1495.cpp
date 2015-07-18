#include <iostream>
#include <algorithm>
using namespace std;
int n;
int array[1002]={0};
int main(){
	int i, j, m = 0;
	cin>>n;
	for(i=0; i<n; ++i){
		cin>>j;
		m = max(m, j);
		++array[j];
	}
	for(i=0; i<=m; ++i){
		for(j=0; j<array[i]; ++j){
			cout<<i<<"\n";
		}
	}
	return 0;
}