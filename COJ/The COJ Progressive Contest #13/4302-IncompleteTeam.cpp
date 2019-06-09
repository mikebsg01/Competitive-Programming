#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(t,i,a,b) for (t i = a; i != b; ++i)
using namespace std;

int T;

int main() {
    optimize_io
    int a, b;
    cin >> T;
    while(T--) {
        cin >> a >> b;
        cout << ((a/__gcd(a, b)) * b) << '\n';
    }
    return 0;
}