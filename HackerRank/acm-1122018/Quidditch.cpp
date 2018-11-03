#include <bits/stdc++.h>
using namespace std;

double M, N;

int main() {
	cin >> M >> N;
	M += 150;

	if (M > N) {
		cout << "yes\n";
	} else {
		double	d = ceil((N - M) / 10),
			x = (10 * d) + 10;
		cout << x << '\n';
	}
	return 0;
}
