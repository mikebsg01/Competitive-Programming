#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int N, K, T[MAXN][MAXN];

void printTable(int n, int m) {
    int i, j;
    for (i = 0; i < n;  ++i) {
        for (j = 0; j < m; ++j) {
            cout << T[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void makeDifferencesTable() {
    int i, j;

    for (j = 1; j < N; ++j) {
        for (i = j; i < N; ++i) {
            T[i][j] = T[i][j-1] - T[i-1][j-1];
        }
    }
}

void makeOperations() {
    int i, j;

    for (i = N; i < N + K; ++i) {
        T[i][N-1] = T[i-1][N-1];

        for (j = N - 2; j >= 0; --j) {
            T[i][j] = T[i-1][j] + T[i][j+1];
        }
    }
}

int main() {
    int i;
    while (cin >> N && N != 0) {
        for (i = 0; i < N; ++i) {
            cin >> T[i][0];
        }
        cin >> K;
        makeDifferencesTable();
        makeOperations();
        cout << "\n";
        printTable(N + K, N);
        cout << "\n\tResultado: " << T[N+K-1][0] << "\n";
        memset(T, 0, sizeof(T));
    }
    return 0;
}
