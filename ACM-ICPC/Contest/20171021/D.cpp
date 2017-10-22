#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int toInt(const char c) {
	return ((int)(c-'0'));
}

char toChar(const int i) {
	return ((char)(i+'0'));
}

int main() {
	int i;
	lli sum = 0;
	string n, temp;

	while (cin >> n) {
		if (n == "0") {
			return 0;
		}

		do {
			temp = "";

			for (i = 0; i < n.size(); ++i) {
				sum += toInt(n[i]);
			}

			while (sum > 0) {
				temp = toChar(sum % 10) + temp;
				sum /= 10;
			}
			n = temp;
		} while (n.size() != 1);
		cout << n << "\n";
	}
	return 0;
}
