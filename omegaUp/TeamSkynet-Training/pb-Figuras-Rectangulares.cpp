#include <bits/stdc++.h>
using namespace std;

inline bool is_square(int &n) {
	int root = sqrt(n);
	
	return (root * root) == n;
}

bool is_rectangle(int &n) {
	for (int i = 2; i * i < n; ++i) {
		if ((n % i) == 0) {
			return true;
			break;
		}
	}
	return false;
}

int main() {
	int n;
	bool isSquare, isRectangle;

	cin >> n;

	isSquare = is_square(n);
	isRectangle = is_rectangle(n);
	
	if (isSquare and isRectangle) {
		cout << "ambos\n";
	} else if (isSquare) {
		cout << "cuadrado\n";
	} else if (isRectangle) {
		cout << "rectangulo\n";
	} else {
		cout << "ninguno\n";
	}
	return 0;
}
