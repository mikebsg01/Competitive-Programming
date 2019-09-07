#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define ITFOR(t,i,a,b) for (t i = a; i != b; ++i)
#define INS(s,x) s.insert(x)
#define UPPER(s,x) s.upper_bound(x)
#define LOWER(s,x) s.lower_bound(x)
#define FIND(s,x) s.find(x)
#define PB(s,x) s.push_back(x)
#define VUPPER(s,x) upper_bound(ALL(s), x) - s.begin()
#define VLOWER(s,x) lower_bound(ALL(s), x) - s.begin()
#define SZ size()
#define ALL(s) s.begin(), s.end()
#define INF -1
using namespace std;
typedef long long int lli;
typedef vector<lli> vectorlli;
typedef set<lli> setlli;

lli A, B;
int N;
setlli X, Y;
vectorlli Z;

void factorize(setlli& s, lli n) {
    for (lli i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            INS(s, i);
            INS(s, n / i);
        }
    }

    INS(s, 1);
    INS(s, n);
}

lli modifiedGCD(lli a, lli b) {
    int x = VLOWER(Z, a),
        y = (VUPPER(Z, b)) - 1;

    return x > y ? INF : Z[y];
}

int main() {
    optimize_io
    lli a, b, val;
    cin >> A >> B >> N;
    factorize(X, A);
    factorize(Y, B);
    
    ITFOR(setlli::iterator, it, X.begin(), X.end()) {
        val = (*it);

        if (FIND(Y, val) != Y.end()) {
            PB(Z, val);
        }
    }

    FOR(int, i, 0, N) {
        cin >> a >> b;
        cout << modifiedGCD(a, b) << '\n';
    }
    return 0;
}