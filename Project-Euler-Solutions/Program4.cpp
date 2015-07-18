#include <iostream>
using namespace std;
int main(){
	
	long long int product = 1, temp = 0, p=0, bestPalindrome=0;
	for(int i=100;i<1000;i++){
		for(int j=100;j<1000;j++){
			product = i*j;
			temp = product;
			p=0;

			while(temp)
			{
				p = (p*10)+(temp%10);
				temp /= 10;
			}
			if(p==product){
				if(p>bestPalindrome){
					bestPalindrome = p;
				}
			}
		}
	}
	cout << bestPalindrome << endl;
	
	return 0;
}