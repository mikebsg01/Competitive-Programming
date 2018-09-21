#include <iostream>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
using namespace std;

int mcd(int a, int b) {
	int t = a;
	a = max(a, b);
	b = min(t, b);

	while (a % b) {
		t = a % b;
		a = b;
		b = t;
	}

	return b;
}

int main() {
	int M, N;

	cin >> M >> N;

	cout << mcd(M, N) << "\n";
	return 0;
}
