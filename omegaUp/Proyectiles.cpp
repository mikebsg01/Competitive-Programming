#include <iostream>
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
optimize
int n, k;
cin >> n >> k;
int array[n][2], array2[k][2];
int res[k];

for(int i=0;i<n;i++){
	cin >> array[i][0] >> array[i][1];
}
for(int j=0;j<k;j++){
	cin >> array2[j][0] >> array2[j][1];
	res[j] = 1;
	
}
for(int a=0;a<k;a++){
	for(int b=0;b<n;b++){
		if(array2[a][0] == array[b][0] && array2[a][1] == array[b][1]){
			res[a] = 0;
		}
	}	
}
for(int x=0;x<k;x++){
	cout << res[x] << endl;
}
return 0;
}
