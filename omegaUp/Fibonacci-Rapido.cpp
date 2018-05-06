#include <iostream>
#include <map>
#define MOD 98765431
using namespace std;
typedef long long int lli;

map<int, int> dp;

lli fib(lli n) {
    if (dp.count(n) > 0) {
        return dp[n];
    }

    if (n == 0) {
        return dp[n] = 0;
    } else if (n == 1 || n == 2) {
        return dp[n] = 1;
    }

    bool isOdd = n & 1;
    lli k = isOdd ? (n + 1) / 2 : n / 2;

    return dp[n] = isOdd ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) % MOD :
                    ((2 * fib(k - 1) + fib(k)) * fib(k)) % MOD;
}

int main() {
    lli N;
    cin >> N;
    cout << fib(N) << "\n";
    return 0;
}