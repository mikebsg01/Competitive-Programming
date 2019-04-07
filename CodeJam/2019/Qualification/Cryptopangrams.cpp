#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i != b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i != b; --i)
#define CFOR(t,i,a,b,c) for (t i = a; i < b; i += c)
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define PUSH(s, x) s.push(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define SZ size()
#define MAXN ((int) (1e4+5))
#define EPS (1e-8)
#define INF -1
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<lli, lli> Pair;
typedef pair<lli, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef pair<Pair, string> cPair;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<Pair> vectorPair;
typedef vector<Tern> vectorTern;
typedef set<lli> setlli;
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef map<lli, char> cmap;
typedef queue<int> qi;
typedef queue<lli> qlli;
typedef queue<Pair> qPair;
typedef queue<cPair> cq;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

class couple {
public:
    lli val[2];

    couple(lli a, lli b) {
        this->val[0] = a;
        this->val[1] = b;
    }
};

int T, N, L;
bool isPrime[MAXN];
vectorlli allPrimes, primes, A;
vector<couple> B;
setlli id;
cmap dict;
bool solved;
lli P[MAXN], p;

void criba() {
    memset(isPrime, true, sizeof(isPrime));
    
    isPrime[0] = isPrime[1] = false;

    CFOR(int, i, 4, MAXN, 2) {
        isPrime[i] = false;
    }

    CFOR(int, i, 3, MAXN, 2) {
        if (isPrime[i]) {
            CFOR(int, j, 2 * i, MAXN, i) {
                isPrime[j] = false;
            }
        }
    }

    FOR(int, i, 0, MAXN) {
        if (isPrime[i]) {
            PB(allPrimes, i);
        }
    }
}

void getPrimes() {
    FOR(int, i, 0, allPrimes.SZ) {
        if (allPrimes[i] > N) {
            break;
        }

        PB(primes, allPrimes[i]);
    }
}

lli findFirstFactor(lli n) {
    lli div;

    FOR(int, i, 0, primes.SZ) {
        if ((primes[i] * primes[i]) > n) {
            break;
        }

        if (n % primes[i]) {
            continue;
        }
    
        div = n / primes[i];

        if (isPrime[div]) {
            return primes[i];
        }
    }
}

bool solve(int idx, lli expected) {
    if (solved) {
        return true;
    } else if (idx >= L) {
        FOR(int, i, 0, p) {
            cout << dict[P[i]];
        }

        cout << dict[expected] << '\n';
        solved = true;
        return true;
    }

    FOR(int, i, 0, 2) {
        P[p++] = B[idx].val[i ^ 1];

        if ((idx == 0 or B[idx].val[i ^ 1] == expected) and solve(idx + 1, B[idx].val[i])) {
            return true;
        }

        P[--p] = 0;
    }

    return false;
}

int main() {
	optimize_io
    char c;
    lli x, a, b;
    criba();
	cin >> T;

	FOR(int, t, 1, T + 1) {
		cin >> N >> L;
        primes.clear();
        A.clear();
        B.clear();
        id.clear();
        dict.clear();
        solved = false;
        p = 0;

        FOR(int, i, 0, L) {
            cin >> x;
            PB(A, x);
        }

        getPrimes();

        FOR(int, i, 0, L) {
            a = findFirstFactor(A[i]);
            b = A[i] / a;
            PB(B, couple(a, b));
            INS(id, a);
            INS(id, b);
        }

        c = 'A';
        FOR(setlli::iterator, it, id.begin(), id.end()) {
            dict[(*it)] = c++;
        }

        cout << "Case #" << t << ": ";
        solve(0, INF);
	}
	return 0;
}
