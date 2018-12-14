#include <bits/stdc++.h>
using namespace std;

int A;

int main() {
	int T, i, j, k, ty, tx;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		cin >> A;
		
		do {
			for (j = 2; j < 2 + (A / 5) - 2; ++j) {
				for (k = 2; k < 2 + 5 - 2; ++k) {
					cout << j << " " << k << endl;
					cin >> ty >> tx;

					if (ty == -1 and tx == -1) {
						return 0;
					} else if (ty == 0 and tx == 0) {
						break;
					}
				}
				if (ty == 0 and tx == 0) {
					break;
				}
			}
		} while (ty != 0 or tx != 0);
	}
	return 0;
}
