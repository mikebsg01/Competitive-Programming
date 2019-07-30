#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(t,i,a,b) for (t i = a; i != b; ++i)
#define FORIT(t,i,s) for (t::iterator i = s.begin(); i != s.end(); ++i)
#define INS(s,x) s.insert(x)
#define SZ size()
using namespace std;
typedef unordered_set<int> seti;

int A, B;
seti X, Y;

int main() {
    optimize_io
    int x, y, t, ans;
    seti ita, itb;

    while ((cin >> A >> B) and (A != 0 or B != 0)) {
        ans = 0;
        X.clear(); Y.clear();

        FOR(int, i, 0, A) {
            cin >> x;
            INS(X, x);
        }

        FOR(int, i, 0, B) {
            cin >> y;
            INS(Y, y);
        }

        ita = X.SZ < Y.SZ ? X : Y;
        itb = Y.SZ > X.SZ ? Y : X;

        FORIT(seti, it, ita) {
            t = (*it);

            if (itb.count(t) == 0) {
                ++ans;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}