#include <bits/stdc++.h>
#define MAXN 200001
#define printArray(array, n)\
    for (int x = 0; x < n; ++x) {\
        cout << array[x] << " ";\
    }\
    cout << endl;
#define view(x) cout<<#x<<": "<<x<<endl;
using namespace std;

bool A[MAXN]; int a, b; // Pivotes A (Inicio) y B (Fin)
int N,      // Cantidad de casas
    K,      // Cantidad de casas con cmara de sguridad
    R;      // Casas consecutivas requeridas con cámara de seguridad
int ans;    // Camaras faltantes

int init() {
    int i, sum = 0;
    a = 0; b = R - 1;
    for (i = a; i <= b; ++i) {
        sum += (int) A[i];
    }
    return sum;
}

int atLeastTwo(int sum) {
    while (sum < 2) {
        if (A[b]) { /* Existe un caso especial si en la posición "b" del arreglo se encuentra una casa que ya
                     * cuenta con una cámara y por error agregamos una más en esa misma posición,
                     * recordando que el problema pide al menos 2 casas DIFERENTES con cámaras de
                     * seguridad en un rango R.
                     */
            A[b - 1] = true;
        } else {
            A[b] = true;
        }
        ++sum;
        ++ans;
    }
    return sum;
}

void scanning() {
    int sum = init();
    sum = atLeastTwo(sum);

    a = a + 1;
    b = b + 1;
    while (b < N) {
        sum -= A[a - 1];
        sum += A[b];
        sum = atLeastTwo(sum);
        ++a;
        ++b;
    }
}

int main() {
    int i, house;
    cin >> N >> K >> R;

    for (i = 0; i < K; ++i) {
        cin >> house;
        A[house - 1] = true;
    }

    scanning();
    cout << ans << endl;
    return 0;
}
