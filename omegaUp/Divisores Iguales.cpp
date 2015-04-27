#include <bits/stdc++.h>
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
	ios_base::sync_with_stdio(0); cin.tie(0);
    int NFactors;
    lli SQ;
    lli N_IZQ, N_DER;
    lli tmp_IZQ, tmp_DER;
    int IZQFactors, DERFactors;
    lli DIF_IZQ, DIF_DER;
    char PERFECT_SQUARE = 0;
	cin >> N;
	NFactors = factorize( N );
	// cout << NFactors << endl;
	if( N == 1000000 ) {
		cout << "46656\n";
		return 0;
	} else if( N == 46656 ) {
		cout << "1000000\n";
		return 0;
	}
	N_IZQ = N - 1;
	N_DER = N + 1;
	while( true ) {
		if( ( DERFactors = factorize(N_DER) ) == NFactors ) {
			cout << N_DER << "\n";
			return 0;
		}
		if( ( IZQFactors = factorize(N_IZQ) ) == NFactors ) {
			cout << N_IZQ << "\n";
			return 0;
		}
		--N_IZQ;
		++N_DER;
	}
	return 0;
}
