/*
ID: program43
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char amigos[15][20], temp[20];
int money_INITIAL[15] = {0}, money_ACTUAL[15]={0}, N=0, i, j=0, ID=0, MONEY=0, NP=0, MONEY_SOB = 0, MONEY_REPART=0;
int main(){
	freopen("gift1.in","rt",stdin);
	freopen("gift1.out","wt",stdout);
	cin >> N;
	for(i=0; i<N; ++i)
		cin >> amigos[i];
	for(i=0; i<N; ++i){
		//cout << "Ingresa Nuevo" << endl;
		cin >> temp;
		ID=0;
		//cout << amigos[ID] << " "<< temp << endl;
		while(strcmp(amigos[ID],temp)){
			//cout <<"F:"<< amigos[ID] << endl;
			ID++;
		}
		//cout << amigos[ID] << endl;
		cin >> MONEY >> NP; 
		money_INITIAL[ID] = (int) MONEY;
		if(NP!=0){	
			MONEY_REPART = (int) MONEY/NP;
			//cout << MONEY_REPART << endl;
			MONEY_SOB = (int) MONEY%NP;
			money_ACTUAL[ID] +=(int) MONEY_SOB;
			//cout << MONEY_SOB << endl;
			for(j=0; j<NP; ++j){
				cin >> temp;
				if(MONEY_REPART!=0){
					ID=0;
					while(strcmp(amigos[ID],temp)){
						ID++;
					}
					//cout << ID << endl;
					money_ACTUAL[ID] += (int) MONEY_REPART;
				}
			}
		}
		//temp = NULL;
	}
	for(i=0; i<N; ++i){
		cout << amigos[i] << " " << ((int)money_ACTUAL[i]-money_INITIAL[i]) << endl;
	}
	return 0;
}

