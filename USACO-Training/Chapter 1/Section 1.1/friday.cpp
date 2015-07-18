/*
ID: program43
PROG: friday
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main(){
	int year = 1900;
	int y=0, i=0, j=0, index = 1;
	int n,x=0;

	int month[13];
	month[1] = 31; // Enero
	month[2] = 28; // Febrero
	month[3] = 31; // Marzo
	month[4] = 30; // Abril
	month[5] = 31; // Mayo
	month[6] = 30; // Junio
	month[7] = 31; // Julio
	month[8] = 31; // Agosto
	month[9] = 30; // Septiembre
	month[10]= 31; // Octubre
	month[11]= 30; // Noviembre
	month[12]= 31; // Diciembre

	int day[8];
	day[1] = 0; // lunes
	day[2] = 0; // martes
	day[3] = 0; // miercoles
	day[4] = 0; // jueves
	day[5] = 0; // viernes
	day[6] = 0; // sabado
	day[7] = 0; // domingo

	freopen("friday.in","rt",stdin);
	freopen("friday.out","wt",stdout);

	cin >> n;
	for(y=1900; y<=(1900+n-1); y++){

		if(y%4==0 && (y%400==0 || y%100!=0)) month[2] = 29; 
		else month[2] = 28;

		for(i=1; i<=12; i++){
			for(j=1; j<=month[i]; j++){
				//cout << index << endl;
				if(j==13){
					day[index] = day[index] + 1;
					/* if(index==2){
						cout <<j<<"/"<<i<<"/"<<y<<endl;					
					} */
				}
				index++;
				if(index>7){
					index=1;
				}
				x++;
			}
		}
		//cout << y << endl;
	}

	cout << day[6] << " "
	     << day[7] << " "
	     << day[1] << " "
	     << day[2] << " "
	     << day[3] << " "
             << day[4] << " "
             << day[5] << endl;

	// cout << x << endl;
	return 0;
}
