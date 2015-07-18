#include <iostream>
#define F 20
#define C 50
#define SIZE 1000
using namespace std;

int main(){

	char buffer[F][C];
	char buffer1[SIZE];

	for(int i=0;i<F;i++)
		for(int j=0;j<C;j++)
			cin >> buffer[i][j];

	int index=0;
	for(int i=0;i<F;i++){
		for(int j=0;j<C;j++){
			buffer1[index] = buffer[i][j];
			index++;
		}
	}

	long long int greatProduct=0, sumProduct=1;
	int array[13];
	int array2[13];
	int index1 = 0;

	for(int i=0;i<SIZE-13;i++){
		sumProduct=1;
		index1 = 0;
		for(int j=i;j<i+13;j++){
			array[index1] = (buffer1[j]-48);
			sumProduct*=(buffer1[j]-48);
			index1++;
		}
		if(sumProduct>greatProduct){
			greatProduct = sumProduct;
			int index2=0;
			for(int x=i;x<i+13;x++){
				array2[index2] = array[index2];
				index2++;
			}
		}

	}
	for(int i=0;i<13;i++){
		if(i!=12)
			cout << array2[i] << "*";
		else
			cout << array2[i];
	}
	cout << " = " << greatProduct << endl;
	return 0;
}