#include <bits/stdc++.h>
#define MAXN 1000005
#define pb push_back
using namespace std;

int N;
int A[MAXN]; int p = 0; int maxP = 0;

int main(){
	int i, j;
	int pot;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	if( N == 0 ){
		cout<<"1\n0\n";
	} else {
		while( N ) {
			pot = 1;
			while( pot <= N ) {
				pot *= 10;
			}
			pot /= 10;
			p = 0;
			for( i = 0; i < (N / pot); ++i ){
				A[p++] += pot;
				//cout<<A[p-1]<<" ";
			}
			//cout << endl;
			maxP = max(maxP, p);
			N  -= ( (N / pot) * pot );
		}
		cout<<maxP<<endl;
		for( i = 0; i < maxP; ++i ){
			cout << A[i] << " ";
		}
		cout << endl;
	}
	return 0; 
}