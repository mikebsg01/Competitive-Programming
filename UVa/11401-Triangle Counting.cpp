#include <bits/stdc++.h>
#define MAXN 12
using namespace std;

int A[MAXN],
    p = 0,
    counter = 0,
    ans = 0;

void combinatorial(int a, int b, int level) {
    int i;

    if (level == 3) {
        //======= View Combination List ======//
        //
        // cout << "( " << A[0];
        // for (i = 1; i < 3; ++i) {
        //    cout << ", " << A[i];
        // }
        // cout << " )\n";
        // 
        //====================================//
        if (A[1] + A[2] > A[0] &&
            A[0] + A[2] > A[1] &&
            A[0] + A[1] > A[2]) {
            ++ans;
        }
        ++counter;
        return;
    }

    for (i = a; i <= b; ++i) {
        A[p++] = i;
        combinatorial(i + 1, b, level + 1);
        A[--p] = 0;
    }
}

int main() {
    int n, i;
    bool repeat = false;
    do {
        cout << "Introduzca el valor de N: ";
        cin>>n;

        if (n < 0 || n > 20) {
            cout << "\n\tEl valor de N es invalido."
                 << "\n\tDebe ser un valor entre 0 y 10\n";
            repeat = true;
        }
    } while (repeat);

    for (i = 1; i <= n; ++i) {
        cout << "Iteracion #" << i << ": \n";
        counter = ans = 0;
        combinatorial(1, i, 0);
        cout << "Total de combinaciones: " << counter << "\n"
             << "Total de triangulos diferentes: " << ans << "\n\n";
    }
    return 0;
}
