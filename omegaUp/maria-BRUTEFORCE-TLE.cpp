#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN (((int) 1e5)+2)
using namespace std;
typedef long long int lli;

int N, A[MAXN];
lli ans;

int main() {
	optimize_ios
	int i, j, minVal;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> A[i];
		minVal = A[i];

		for (j = i; j >= 0; --j) { 
			minVal = min(minVal, A[j]);
			ans += minVal;
		}
	}

	cout << ans << '\n';
	return 0;
}
