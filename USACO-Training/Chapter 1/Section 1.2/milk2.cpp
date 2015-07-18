/*
ID: program43
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	freopen("milk2.in", "rt", stdin);
	freopen("milk2.out", "wt", stdout);
	pair<int, int> inter[5010];
	int N, i, j, a, b;
	int max = 0, min = 1000001;
	int inf = 0, sup = 0;
	int act = 0, ina = 0;
	cin >> N;

	for( i = 1; i <= N; ++i ){

		cin >> inter[i].first >> inter[i].second;

	}

	sort( inter, inter + N + 1 );

/*

	cout << "\n\n===========================\n";

	for( i = 1; i <= N; ++i ){

		cout << inter[i].first << " " << inter[i].second << "\n";

	}

	cout << "\n===========================\n\n";

*/

	for ( i = 1; i <= N; ++i ) {

		if ( inter[i].first < min ) {

			min = inter[i].first;

		}

		if ( inter[i].second > max ) {

			max = inter[i].second;

		}

	}

	i = 1;

	while ( i <= N ) {

		a =  inter[i].first;
		b =  inter[i].second;
		inf = a;
		sup = b;
		j = i+1;

		while ( inter[j].first <= sup && j <= N ) {


			if( inter[j].second > sup ) {

				sup = inter[j].second;

			}

			++j;

		}

		if ( inf <= min && sup >= max  ) {

			act = sup - inf;
			ina = 0;
			break;

		} else {

			if( ( sup - inf ) > act ) {

				act = sup - inf;

			}

			if ( ( inter[j].first - sup ) > ina ) {

				ina  = inter[j].first - sup;

			}

		}

		i = j;

	}

	cout << act << " " << ina << endl;

	return 0;
}