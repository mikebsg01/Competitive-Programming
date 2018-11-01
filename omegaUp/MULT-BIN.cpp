#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
using namespace std;

class Binary {
private:
	string a;

	inline int tobit(char c) {
		return ((int) (c - '0'));
	}

	inline char tochar(int b) {
		return ((char) (b + '0'));
	}

	string sanitize(string s) {
		int i = 0, n = s.size();
		
		while (s[i] == '0' and i < n) {
			++i;
		}

		return (i < n) ? s.substr(i, n - i) : string("");
	}

public:
	static const int base = 2;

	Binary() {
		this->a = "";
	}

	Binary(string s) {
		this->assign(s);
	}

	void assign(string s) {
		this->a = this->sanitize(s);	
	}

	int size() {
		return this->a.size();
	}

	char at(int idx) {
		return this->a[idx];
	}

	char operator[] (int idx) {
		return this->a[idx];
	}

	string toString() {
		return this->a;
	}

	Binary multiply(Binary b) {
		int i, j, n, m, p;
		string strA = this->toString(), strB = b.toString(), strC("");
		int current, add, update, carry;
		reverse(strA.begin(), strA.end());
		reverse(strB.begin(), strB.end());

		for (i = 0, n = strB.size(); i < n; ++i) {
			for (carry = 0, j = 0, m = strA.size(), p = strC.size(); j < m; ++j) {
				add = tobit(strB[i]) * tobit(strA[j]);
					
				if ((i > 0) and ((i + j) < p)) {
					current = tobit(strC[i + j]);
					update = current + add + carry;
					carry = update / this->base;
					strC[i + j] = tochar(update % this->base);
				} else {
					update = add + carry;
					carry = update / this->base;
					strC += tochar(update % this->base);
				}
			}

			for (j = 0; j < carry; ++j) {
				strC += '1';
			}
		}

		reverse(strC.begin(), strC.end());
		return Binary(strC);
	}
};

string A, B;

int main() {	
	cin >> A >> B;
	Binary a(A), b(B);
	cout << a.multiply(b).toString() << '\n';
	return 0;
}
