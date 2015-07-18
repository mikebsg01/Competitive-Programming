#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(long long int num){
	if(num==2 || num==1)
		return true;
	else
		for(long long int i=2;i<=sqrt(num);i++)
			if(num%i==0)
				return false;
	return true;
}
int main(){

	bool prime = false;
	int numPrimes = 0;

	long long int num=1;
	while(numPrimes<=10001){
		prime = isPrime(num);
		if(prime){
			numPrimes++;
		}
		num++;
	}
	cout << num-1 << endl;

	return 0;
}