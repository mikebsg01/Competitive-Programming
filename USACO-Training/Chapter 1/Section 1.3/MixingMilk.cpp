/*
ID: program43
PROG: milk
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int N,M;
pair<int,int> A[5002];
int main(){
	freopen("milk.in","rt",stdin);
	freopen("milk.out","wt",stdout);
	int i;
	int a,b;
	cin>>N>>M;
	for(i=0; i<M; ++i){
		cin>>a>>b;
		A[i].X = a;
		A[i].Y = b;
	}
	sort(A, A+M);
	i = 0;
	long long int answer = 0;
	while(N){
		if(A[i].Y<=N){
			answer += (A[i].Y*A[i].X);
			N -= A[i].Y;
			++i;
		} else {
			answer += ((N)*A[i].X);
			N = 0;
		}
	}
	cout<<answer<<"\n";
	return 0;
}