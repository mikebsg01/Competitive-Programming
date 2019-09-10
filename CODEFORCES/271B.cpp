#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define CFOR(t,i,a,b,c) for (t i = a; i < b; i += c)
#define LOWER(s,x) (lower_bound(s.begin(), s.end(), x) - s.begin())
#define PB(s,x) s.push_back(x)
#define SZ size()
#define MAXN (505)
#define MAXP (100005)
#define INF -1
using namespace std;
typedef vector<int> vectori;

int N, M, T[MAXN][MAXN], ans = INT_MAX;
bool isPrime[MAXP];
vectori primes;

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    isPrime[2] = true;
    PB(primes, 2);

    CFOR(int, i, 4, MAXP, 2) {
        isPrime[i] = false;
    }

    CFOR(int, i, 3, MAXP, 2) {
        if (isPrime[i]) {
            PB(primes, i);

            CFOR(int, j, 2 * i, MAXP, i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    optimize_io
    int x, pos, a, b, moves;
    cin >> N >> M;
    sieve();

    FOR(int, i, 0, N) {
        moves = 0;

        FOR(int, j, 0, M) {
            cin >> x;
            T[i][j] = x;
            pos = LOWER(primes, x);
            moves += abs(primes[pos] - x);
        }

        ans = min(ans, moves);
    }

    FOR (int, j, 0, M) {
        moves = 0;

        FOR(int, i, 0, N) {
            x = T[i][j];
            pos = LOWER(primes, x);
            moves += abs(primes[pos] - x);
        }

        ans = min(ans, moves);
    }

    cout << ans << '\n';
    return 0;
}