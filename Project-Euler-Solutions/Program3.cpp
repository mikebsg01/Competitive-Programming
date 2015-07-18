#include <iostream>
#include <cmath>
using namespace std;
long long int isFactor(long long int num){

	for(int i=2;i<=sqrt(num);i++)
		if(num%i==0)
			return i;

	return num;
}

int main(){

	long long int num = 600851475143, f = 0, bigFactor = 0;
	while(num>1){
		f = isFactor(num);
		num = num/f;
		if(f>bigFactor){
			bigFactor = f;
		}
	}
	cout << bigFactor << endl;
	return 0;
}