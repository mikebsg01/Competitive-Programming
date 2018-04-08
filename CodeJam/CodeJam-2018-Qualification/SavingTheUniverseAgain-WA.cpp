#include <bits/stdc++.h>
#define PB push_back
#define SZ size()
#define dd(x) cout << #x << ": " << x << "\n"
using namespace std;

int T, D, ans;
string S;
vector<int> A;

int main() {
	int i, j, shots, maxStrength, strength, damage;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		cin >> D >> S;

		ans = shots = 0;

		for (j = S.SZ - 1; j >= 0; --j) {
			if (S[j] == 'S') {
				++shots;
			} else {
				A.PB(shots);
			}
		}

		if (shots > D) {
			cout << "Case #" << i << ": IMPOSSIBLE\n";
			continue;
		}
		
		strength = 1;
		damage = 0;

		for (j = 0; j < S.SZ; ++j) {
			if (S[j] == 'S') {
				damage += strength;	
			} else {
				strength <<= 1;
			}
		}

		maxStrength = strength;
		j = 0;

		while (damage > D and j < A.SZ) {
			if (!A[j]) {
				++j;
				maxStrength >>= 1;
				continue;
			}

			damage -= maxStrength / 2;
			--A[j];
			++ans;
		}

		cout << "Case #"<< i << ": " << ans << "\n";
		A.clear();
	}	
	return 0;
}
