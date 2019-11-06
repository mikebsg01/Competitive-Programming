#include <iostream>
#include <cmath>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
using namespace std;
typedef long long int lli;

lli n;

int main() {
    optimize_io
    lli i, j, b, m, ans;
    bool solved;

    while((cin >> n) and n >= 0) {
        b = sqrt(n) + 1;
        solved = false;

        for (i = b; i >= 2; --i) {
            m = n;

            for (j = 0; j < i and m % i == 1; ++j) {
                m = ((m - 1) * (i - 1)) / i;
            }

            if (i == j and m % i == 0) {
                solved = true;
                ans = i;
                break;
            }
        }

        cout << n << " coconuts, ";

        if (solved) {
            cout << ans << " people and 1 monkey\n";
        } else {
            cout << "no solution\n";
        }
    }
    return 0;
}