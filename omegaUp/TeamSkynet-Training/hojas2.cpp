#include <iostream>
#include <cmath>
using namespace std;

int N, B;
double C;

int countDigits() {
	int digits = 0, counter = 0;
	double pot = 1;

	while (pot <= N) {
		pot *= B;
		++digits;

		if (N >= pot) {
			counter += ((pot - (pot/B)) * digits);
		} else {
			counter += (N - (pot/B) + 1) * digits;
		}
	}

	return counter;
}

int main() {
	int i, digits, ans;
	double div, sum = 0;

	cin >> N >> B >> C;
	
	sum = countDigits();
	div = sum / C;
	ans = ceil(div);
	
	cout << ans << "\n";
	return 0;
}
