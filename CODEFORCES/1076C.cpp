#include <iostream>
#include <cmath>
#include <iomanip>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define EPS (1e-6)
using namespace std;

int T;

inline bool lessThanZero(double n) {
    return n < -EPS;
}

void solve(double d) {
    double det = (d * d) - (4.0 * d);

    if (lessThanZero(det)) {
        cout << "N\n";
        return;
    }

    double  a = (d + sqrt(det)) / 2.0,
            b = d - a;

    cout << "Y " << a << ' ' << b << '\n';
}

int main() {
    optimize_io
    double d;
    cin >> T;
    cout << fixed << setprecision(9);

    for (int i = 0; i < T; ++i) {
        cin >> d;
        solve(d); 
    }
    return 0;
}