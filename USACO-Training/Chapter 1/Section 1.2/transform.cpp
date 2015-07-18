/*
ID: program43
PROG: transform
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

char square[11][11];
char transform[11][11];
int N, i, j;

bool t90() {

	int x, y;

	x = 1;

	for( j = 1; j <= N; ++j ) {

		y = 1;

		for( i = N; i >= 1; --i ) {

			if( transform[x][y] != square[i][j] ) {

				return false;

			}

			++y;
		}

		++x;
	}

	return true;
}

bool t180() {

	int x, y;

	x = 1;

	for ( i = N; i >= 1; --i ) {

		y = 1;

		for ( j = N; j >= 1; --j ) {

			if ( transform[x][y] != square[i][j] ) {

				return false;

			}

			++y;
		}

		++x;

	}

	return true;

}

bool t270() {

	int x, y;

	x = 1;

	for ( j = N; j >= 1; --j ) {

		y = 1;

		for ( i = 1; i <= N; ++i ) {

			if ( transform[x][y] != square[i][j] ) {

				return false;

			}

			++y;

		}

		++x;

	}

	return true;

}

bool tHorizontal() {

	int x, y;

	x = 1;

	for ( i = 1; i <= N; ++i ) {

		y = 1;

		for ( j = N; j >= 1; --j ) {

			if ( transform[x][y] != square[i][j] ) {

				return false;

			}

			++y;

		}

		++x;
 
	}

	return true;

}

bool tHorizontalCombination() {

	int x, y;

	bool is_solution1 = true, is_solution2 = true, is_solution3 = true;

	x = 1;

	for ( j = N; j >= 1; --j ) {

		y = 1;

		for ( i = N; i >= 1; --i ) {

			if ( transform[x][y] != square[i][j] ) {

				is_solution1 = false;

				break;

			}

			++y;

		}

		if ( !is_solution1 ) {

			break;

		}

		++x;

	}

	x = 1;

	for ( j = 1; j <= N; ++j ) {

		y = 1;

		for ( i = 1; i <= N; ++i ) {

			if ( transform[x][y] != square[i][j] ) {

				is_solution2 = false;

				break;

			}

			++y;

		}

		if ( !is_solution2 ) {

			break;

		}

		++x;

	}

	x = 1;

	for ( i = N; i >= 1; --i ) {

		y = 1;

		for ( j = 1; j <= N; ++j ) {

			if ( transform[x][y] != square[i][j] ) {

				is_solution3 = false;

				break;

			}

			++y;

		}

		if ( !is_solution3 ) {

			break;

		}

		++x;

	}


	if ( is_solution1 || is_solution2 || is_solution3 ) {

		return true;

	}

	return false;

}

bool noChanges() {

	for ( i = 1; i <= N; ++i ) {

		for ( j = 1; j <= N; ++j ) {

			if ( transform[i][j] != square[i][j] ) {

				return false;

			}

		}

	}

	return true;

}

int transformation() {

	if ( t90() ) { 

		return 1;

	} else { 

		if ( t180() ) {

			return 2;

		} else {

			if ( t270() ) {

				return 3;

			} else {

				if ( tHorizontal() ) {

					return 4;

				} else {

					if ( tHorizontalCombination() ) {

						return 5;

					} else {

						if ( noChanges() ) { 

							return 6;

						}

					}

				}

			}

		}

	}

	return 7;

}

int main(){

	freopen("transform.in", "rt", stdin);
	freopen("transform.out", "wt", stdout);

	cin >> N;

	for( i = 1; i <= N; ++i ) {

		for( j = 1; j <= N; ++j) {

			cin >> square[i][j];

		}

	}

	for( i = 1; i <= N; ++i ) {

		for( j = 1; j <= N; ++j) {

			cin >> transform[i][j];

		}

	}

	cout << transformation() << endl;

	return 0;
}