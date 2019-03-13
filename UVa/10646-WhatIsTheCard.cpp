#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,b,a) for (int i = b; i > a; --i)
#define PB push_back
#define MP make_pair
#define SZ size()
#define X first
#define Y second
#define CARDS 52
#define HAND 25
using namespace std;
typedef pair<char, char> Pair;

int T;
short Y;
deque<Pair> A, B;

inline short val(char v) {
	return isdigit(v) ? ((short) (v - '0')) : 10;
}

int main() {
	optimize_io
	char v, s;
	short x;
	Pair ans;

	cin >> T;

	FOR(i, 0, T) {
		Y = 0; A.clear(); B. clear();

		FOR (j, 0, CARDS) {
			cin >> v >> s;
			A.push_front(MP(v, s));
		}

		FOR (j, 0, HAND) {
			B.push_front(A.front());
			A.pop_front();
		}

		FOR(j, 0, 3) {
			x = val(A.front().X);
			A.pop_front();
			Y += x;
			x = 10 - x;

			FOR(k, 0, x) {
				A.pop_front();
			}
		}

		FOR(j, 0, HAND) {
			A.push_front(B.front());
			B.pop_front();
		}

		FOR(j, 0, Y - 1) {
			A.pop_back();
		}

		ans = A.back();
		cout << "Case " << (i + 1) << ": " << ans.X << ans.Y << "\n";
	}
	return 0;
}
