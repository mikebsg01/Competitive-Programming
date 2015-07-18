/*
ID: program43
PROG: ride
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char cometa[10], grupo[10];
int i=0, PC = 1, PG = 1;
int main(){
	freopen("ride.in","rt",stdin);
	freopen("ride.out","wt",stdout);
	cin >> cometa;
	cin >> grupo;
	for(i=0; i<strlen(cometa); i++)
		PC *= cometa[i]-64;
	for(i=0; i<strlen(grupo); i++)
		PG *= grupo[i]-64;
	//cout << PC%47 << " " << PG%47 << endl;
	if(PC%47==PG%47)
		cout << "GO" << endl;
	else
		cout << "STAY" << endl;
	return 0;
}
