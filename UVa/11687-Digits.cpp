#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
using namespace std;

string toString(int n) {
	ostringstream oss;
	oss << n;
	return oss.str();
}

int countDigits(int n) {
	int d = 0;

	while (n > 0) {
		n /= 10;
		++d;
	}

	return d;
}

int main() {
	optimize_io
	int i, prev, current;
	string s, t;

	while (cin >> s, s != "END") {
		i = 1;
		t = toString(s.size());

		if (s != t) {
			current = prev = atoi(t.c_str());

			do {
				i += 1;
				prev = current;
				current = countDigits(prev);
			} while (current != prev);
		}

		cout << i << '\n';
	}
	return 0;
}
