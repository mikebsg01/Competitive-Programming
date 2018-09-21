#include <iostream>
#include <vector>
#define MAXN 1026
#define PB push_back
#define dd(x) cout << #x << ": " << x << "\n"
#define ddp(y, x) cout << #x << ": " << x << " " << #y << ": " << y << "\n"
using namespace std;

typedef struct Coords {
	int L, B, R, T;
} Coords;

int S;
int BIT[MAXN][MAXN];

void update(int y, int x, int val) {
	int xt;

	while (y <= S) {
		xt = x;
		while (xt <= S) {
			BIT[y][xt] += val;
			xt += xt & (-xt);
		}
		y += y & (-y);
	}
}

int query(int y, int x) {
	int xt, s = 0;

	while (y > 0) {
		xt = x;

		while(xt > 0) {
			s += BIT[y][xt];

			xt -= xt & (-xt);
		}
		y -= y & (-y);
	}
	return s;
}

int rangeQuery(int y1, int x1, int y2, int x2) {
	int a, b, c, d;	

	a = query(y2, x2);
	b = query(y2, x1 - 1);
	c = query(y1 - 1, x2);
	d = query(y1 - 1, x1 - 1);

	return a - b - c + d;
}

int main() {
	int X, Y, A, L, B, R, T, option;

	cin >> S;
	
	while (cin >> option) {
		if (option == 3) {
			break;
		} else if (option == 1) {
			cin >> X >> Y >> A;
			update(X + 1, Y + 1, A);
		} else {
			cin >> L >> B >> R >> T;
			cout << rangeQuery(L + 1, B + 1, R + 1, T + 1) << "\n";
		}
	}
	return 0;
}
