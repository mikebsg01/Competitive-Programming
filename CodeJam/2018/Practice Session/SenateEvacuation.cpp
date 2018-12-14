#include <bits/stdc++.h>
#define X first
#define Y second
#define dd(p) cout << "(" << senators(p) << "," << (*p).Y << ")"
using namespace std;
typedef pair<int, char> P;

int T, N, S;
set<P> H;

inline int half(int n) {
	return ((int)(n / 2));
}

inline int senators(set<P>::iterator it) {
	return -1 * (*it).X;
}

inline int senatorsP(P p) {
	return -1 * p.X;
}

inline P newValue(P p, int add) {
	P tp(p.X + (-1 * add), p.Y);
	return tp;
}

inline char party(P p) {
	return p.Y;
}

void printSet() {
	cout << ">:";
	for (set<P>::iterator it = H.begin(); it != H.end(); ++it) {
                dd(it);
        }
        cout << "\n";
}

void play() {
	int i = 0;
	set<P>::iterator a, b;
	P p, p1, p2;

	while (S > 0) {
		// printSet();
		++i;

		if (i > 1) {
			cout << " "; 
		}

		a = H.begin();
		p = newValue(*a, -2);
		H.erase(a);
		H.insert(p);

		if (senators(H.begin()) <= half(S - 2) and senatorsP(p) >= 0) {
			cout << party(p) << party(p);
			S -= 2;
			continue;
		}

		H.erase(p);
		p1 = newValue(p, 1);
		b = H.begin();
		p2 = newValue(*b, -1);
		H.erase(b);
		H.insert(p1);
		H.insert(p2);

		if (senators(H.begin()) <= half(S - 2)) {
			cout << party(p1) << party(p2);
			S -= 2;
			continue;
		}

		H.erase(p1);
		H.erase(p2);
		p2 = newValue(p2, 1);
		H.insert(p2);
		H.insert(p1);
		cout << party(p1);
		--S;
	}
	cout << "\n";
}

int main() {
	int x;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		S = 0;

		cin >> N;
		
		for (int j = 0; j < N; ++j) {
			cin >> x;
			S += x;
			P p(-1 * x, 'A' + j);
			H.insert(p);
		}
		
		cout << "Case #" << (i + 1) << ": ";
		play();
		H.clear();
	}
	return 0;
}
