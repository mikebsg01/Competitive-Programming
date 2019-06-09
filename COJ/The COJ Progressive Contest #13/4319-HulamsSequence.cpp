#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i != b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i != b; --i)
#define PB(s, x) s.push_back(x)
#define SZ size()
#define MAXN ((int)(1e4))
#define INF 0
using namespace std;
typedef unsigned long long int ulli;

int T;
vector<ulli> hulam;

ulli next() {
    ulli prev,
        current,
        idx = hulam.SZ - 1,
        last = hulam[idx];

    FOR(int, i, 0, idx) {
        if (i > 0) {
            current = hulam[i] + last;

            if ((prev + 1) != current) {
                return (prev + 1);
            }

            prev = current;
        } else {
            prev = hulam[i] + last;
        }
    }
    return (current + 1);
}

void precalculate() {
    PB(hulam, 1);
    PB(hulam, 2);
    PB(hulam, 4);
    
    FOR(int, i, 0, MAXN) {
        int num = next();
        PB(hulam, num);
    }
}

int main() {
    optimize_io
    precalculate();
    int n;
    cin >> T;

    while(T--) {
        cin >> n;
        cout << hulam[n - 1] << '\n';
    }
    return 0;
}