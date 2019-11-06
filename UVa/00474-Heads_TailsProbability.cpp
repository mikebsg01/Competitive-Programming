#include <iostream>
#include <iomanip>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN ((int)(1e6))
using namespace std;

double coefficient[MAXN + 2];
int exponent[MAXN + 2];

void format(double& n) {
    while (n < 1.0) {
        n *= 10;
    }
}

void precalculate() {
    double p = 1;
    int e = 0;

    for (int i = 1; i <= MAXN; ++i) {
        e = (int(p) == 1) ? (e + 1) : e;
        p /= 2;
        format(p);
        coefficient[i] = p;
        exponent[i] = e;
    } 
}

int main() {
    optimize_io
    int n;

    cout << fixed << setprecision(3);
    precalculate();

    while (cin >> n) {
        cout << "2^-" << n << " = " << coefficient[n] << "e-" << exponent[n] << '\n';
    }
    return 0;
}