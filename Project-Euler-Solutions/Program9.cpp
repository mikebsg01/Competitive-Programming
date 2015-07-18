#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	int t;
	while(b) {
		t = b;
		b = a % b;
		a = t;
	} 
	return a;
}

int main(){

	long long int i, j, result = 0;
	float k = 0;

	for ( i = 1; i <= 1000; ++i ) {

		for ( j = 1; j <= 1000; ++j ) {

			k = (float) sqrt(( i *i ) + ( j * j ));

			if ( ( i + j + k ) == 1000 ) {

				result = i * j * k;

				cout << result << endl;

				break;

			} 

		}

		if ( ( i + j + k ) == 1000 ) {

				break;

		}

	}
	

	return 0;
}