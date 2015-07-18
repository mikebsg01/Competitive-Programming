#include <iostream>
using namespace std;
bool notUnity(int* array){
	for(int i=1;i<=20;i++)
		if(array[i-1]!=1)
			return true;

	return false;
}
int main(){
	int array[20];
	for(int i=1;i<=20;i++)
		array[i-1] = i;

	int div = 2;
	bool changes = false;
	long long int mcm = 1;

	while(notUnity(array)){
		changes = false;
		for(int i=1;i<=20;i++)
			if(array[i-1]%div==0){
				array[i-1] = array[i-1] / div;
				changes = true;
			}
		if(!changes)
			div++;
		else
			mcm *= div;
	}
	cout << mcm << endl;
	return 0;
}