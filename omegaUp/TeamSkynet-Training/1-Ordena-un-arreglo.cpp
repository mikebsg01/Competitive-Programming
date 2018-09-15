#include <bits/stdc++.h>
#define PB push_back
using namespace std;

int N;
vector<int> A;

int main() {
	int i, x;

	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> x;
		A.PB(x);
	}

	sort(A.begin(), A.end(), [] (const int a, const int b) { 
		return a > b;
	});

	for (i = 0; i < N; ++i) {
		if (i) {
			cout << " ";
		}
		
		cout << A[i];
	}

	cout << "\n";
	return 0;
}
