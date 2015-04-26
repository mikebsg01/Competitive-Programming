#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j, k;
	string tmp;
	cin>>S;
	N = S.size();
	for( i = 0; i < N; ++i ) {
		for( j = i; j < N; ++j ) {
			tmp.clear();
			for( k = 0; k < i; ++k ) {
				tmp += S[k];
			}
			for( k = j + 1; k <	N; ++k ) {
				tmp += S[k];
			}
			if( tmp.compare("CODEFORCES") == 0 ) {
				cout<<"YES\n";
				return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}