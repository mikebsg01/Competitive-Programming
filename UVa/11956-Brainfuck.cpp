#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
#define dd(x) cout << #x << ": " <<x<<endl;
#define BYTE_SIZE 256
#define BYTES_COUNT 100
#define BASE 16
using namespace std;

string getHex(short n) {
	short t;
	string digits("0123456789ABCDEF"), s("");

	while (n > 0) {
		t = n % BASE;
		s = digits[t] + s;
		n /= BASE;
	}

	if (s.size() == 0) {
		return "00";
	} else if (s.size() == 1) {
		return "0" + s;
	}
	return s;
}

int main() {
	int t, i;
	short j, p, A[BYTES_COUNT] = {0}, add;
	char c;
	
	cin >> t;
	cin.ignore();

	for (i = 0; i < t; ++i) {
		p = 0;

		while ((c = getchar()) != '\n') {
			if (c == '+' or c == '>') {
				add = 1;
			} else if (c == '-' or c == '<') {
				add = -1;
			} else {
				continue;
			}

			if (c == '+' or c == '-') {
				A[p] = (BYTE_SIZE + A[p] + add) % BYTE_SIZE;
			} else {
				p = (BYTES_COUNT + p + add) % BYTES_COUNT;
			}
		}

		cout << "Case " << (i + 1) << ":";
		for (j = 0; j < BYTES_COUNT; ++j) {
			cout << " " << getHex(A[j]);
		}
		cout << "\n";
		memset(A, 0, sizeof(A));
	}	
	return 0;
}
