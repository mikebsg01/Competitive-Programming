#include <bits/stdc++.h>
using namespace std;

int T, D, ans;
string S;

int calcDamage() {
	int i, damage = 0, strength = 1;

	for (i = 0; i < S.size(); ++i) {
		if (S[i] == 'S') {
			damage += strength;
		} else {
			strength *= 2;
		}
	}

	return damage;
}

bool canChange() {
	int i;

	for (i = S.size() - 1; i >= 0; --i) {
		if (S[i] == 'C' and (i + 1) < S.size() and S[i + 1] == 'S') {
			return true;
		}
	}
	return false;
}

void change() {
	int i;

	for (i = S.size() - 1; i >= 0; --i) {
		if (S[i] == 'C' and (i + 1) < S.size() and S[i + 1] == 'S') {
			swap(S[i], S[i + 1]);
			return;
			break;
		}
	}
}

int main() {
	int i, j, damage;

	cin >> T;

	for (i = 1; i <= T; ++i) {
		cin >> D >> S;

		ans = 0;
		damage = calcDamage();

		if (damage <= D) {
			cout << "Case #" << i << ": 0\n";
			continue;
		} 

		while (calcDamage() > D and canChange()) {
			change();
 			++ans;
		}

		if (calcDamage() <= D) {
			cout << "Case #" << i << ": " << ans << "\n";
		} else {
			cout << "Case #" << i << ": IMPOSSIBLE\n";
		}
	}
	return 0;
}
