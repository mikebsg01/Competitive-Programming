
#include <iostream>
#include <cmath>
using namespace std;

void criba( bool* m, int tam ) {

	int i, h;

	m[0] = false;
	m[1] = false;

	for ( i = 2; i <= tam; ++i )
		m[i] = true;

	for ( i = 2; i * i <= tam; ++i ) {

		if ( m[i] ) {

			for ( h = 2; i * h <= tam; ++h ) {

				m[i*h] = false;

			}

		}

	}

}

int main(){

	bool Primes[2000000];
	int N =  2000000;
	long long int Answer = 0;
	int i;

	criba( Primes, N );

	for ( i = 2; i < N; ++i ) {

		if ( Primes[i] ) 
			Answer += i;

	}

	cout << Answer << endl;

	return 0;
}

// Answer: 142913828922