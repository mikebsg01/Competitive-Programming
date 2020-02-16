#include <iostream>
#include <stack>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int M, N;
stack<int> S;

int solve(int idx) {
	if (idx == N) {
		return 0;
	}
	
	int x;
	cin >> x;
	int sum = solve(idx + 1);

	if (sum + x <= M) {
		S.push(idx);
		return sum + x;
	}

	return sum;
}

int main() {
	optimize_io 
	cin >> M >> N;
	solve(0);
	cout << S.size() << '\n';

	for (int i = 0; ! S.empty(); ++i) {
		if (i > 0) {
			cout << ' ';
		}

		cout << S.top();
		S.pop();
	}

	cout << '\n';
	return 0;
}