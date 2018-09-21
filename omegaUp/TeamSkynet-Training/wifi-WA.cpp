#include <iostream>
#include <vector>
#define MAXN 1025
#define PB push_back
using namespace std;

typedef struct Coords {
	int L, B, R, T;
} Coords;

int S;
int DP[MAXN][MAXN];
vector<Coords> V;

void printMatrix() {
	int i, j;

	for (i = 0; i < S; ++i) {
		for (j = 0; j < S; ++j) {
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

inline int dp(int y, int x) {
	if (y < 0 or x < 0) {
		return 0;
	}

	return DP[y][x];
}

void preprocess() {
	int i, j;

	cout << "PREPROCESS: \n";

	for (i = 0; i < S; ++i) {
		for (j = 0; j < S; ++j) {
			DP[i][j] = dp(i, j - 1) + dp(i, j) + dp(i - 1, j) - dp(i - 1, j - 1);
		}
	}
}

inline int submatrixSumQuery(int y1, int x1, int y2, int x2) {
	return dp(y2, x2) - dp(y2, x1 - 1) - dp(y1 - 1, x2) + dp(y1 - 1, x1 - 1);
}

int main() {
	int X, Y, A, L, B, R, T, option;
	Coords tmp;

	cin >> S;
	
	while (cin >> option) {
		if (option == 3) {
			break;
		} else if (option == 1) {
			cin >> X >> Y >> A;
			DP[Y][X] += A;
		} else {
			cin >> L >> B >> R >> T;
			tmp.L = L;
			tmp.B = B;
			tmp.R = R;
			tmp.T = T;
			V.PB(tmp);	
		}
	}
	
	printMatrix();
	preprocess();
	printMatrix();

	int n = V.size(), i;

	for (i = 0; i < n; ++i) {
		tmp = V[i];

		cout << submatrixSumQuery(tmp.B, tmp.L, tmp.T, tmp.R) << "\n";
	}
	return 0;
}
