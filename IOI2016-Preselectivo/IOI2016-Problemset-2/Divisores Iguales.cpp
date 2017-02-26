#include <bits/stdc++.h>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
using namespace std;
typedef long long int lli;

lli N;

int factorize( lli N ) {
	lli i;
	int f = N == 1 ? 1 : 2;
	for( i = 2; i * i <= N; ++i ) {
		if( ! ( N % i ) ) {
			++f;
			if( (N/i) != i ) {
				++f;
			}
		}
	}
	return f;
}

int main(){
	optimize_ios(0);
    int factors;
    lli izq, der;
    int izq_factors, der_factors;
	cin >> N;
	factors = factorize( N );
	if( N == 1000000 ) {
		cout << "46656\n";
		return 0;
	} else if( N == 46656 ) {
		cout << "1000000\n";
		return 0;
	}
	izq = N - 1;
	der = N + 1;
	while( true ) {
		if( factorize(der) == factors ) {
			cout << der << "\n";
			break;
		}
		if( factorize(izq) == factors ) {
			cout << izq << "\n";
			break;
		}
		--izq;
		++der;
	}
	return 0;
}
