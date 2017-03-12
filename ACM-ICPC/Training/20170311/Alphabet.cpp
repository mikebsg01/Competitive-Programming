#include <bits/stdc++.h>
#define MAXN 28
#define MAXM 52
#define printMatrix(matrix, n, m)\
    for (int x = 0; x <= n; ++x) {\
        for (int y = 0; y <= m; ++y) {\
            cout << matrix[x][y] << " ";\
        }\
        cout << endl;\
    }
using namespace std;

char A[MAXN]; int N = 26; // El String Original (El Alfabeto)
char B[MAXM]; int M; // El String dado (A comparar)
int DP[MAXN][MAXM]; // Matriz utilizada para la DP del Algoritmo: Longest Common Subsequence (LCS)

void init() {
    for (int i = 0; i < 26; ++i)
        A[i] = 'a' + i;
}

int LCS(int n, int m) {
    init();
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (A[i - 1] == B[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
    // Macro para visualizar el contenido de la matriz:
    // printMatrix(DP, n, m);
    return DP[n][m];
}

int main() {
    cin >> B;
    M = strlen(B);
    cout << N - LCS(N, M) << endl;
    return 0;
}
