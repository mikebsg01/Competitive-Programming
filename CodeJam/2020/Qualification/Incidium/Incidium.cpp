#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 55
using namespace std;

int T, N, K, M[MAXN][MAXN];
bool solved;

bool is_valid(const int row, const int column, const int val) {
    for (int i = 0; i < row; ++i) {
        if (M[i][column] == val) {
            return false;
        }
    }

    for (int i = 0; i < column; ++i) {
        if (M[row][i] == val) {
            return false;
        }
    }

    return true;
}

int get_trace() {
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        sum += M[i][i];
    }

    return sum;
}

void print_solution() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (j > 0 ? " " : "") << M[i][j];
        }
        cout << "\n";
    }
}

void backtrack(int row, int column) {
    if (solved) {
        return;
    } else if (column == N) {
        if (get_trace() == K) {
            solved = true;
            cout << "POSSIBLE\n";
            print_solution();
        }
        return;
    } else if (row == N) {
        backtrack(0, column + 1);
    } else if (row < N) {
        for (int val = 1; val <= N; ++val) {
            if (is_valid(row, column, val)) {
                M[row][column] = val;
                backtrack(row + 1, column);
            }
        }
    }
}

int main() {
    optimize_io
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> N >> K;
        memset(M, 0, sizeof(M));
        solved = false;
        cout << "Case #" << (i + 1) << ": ";
        backtrack(0, 0);

        if (! solved) {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}