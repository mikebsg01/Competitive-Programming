#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i > b; --i)
#define CFOR(t,i,a,b,c) for (t i = a; i < b; i += c)
#define ITFOR(t,i,a,b) for (t i = a; i != b; ++i)
#define MP make_pair
#define X first
#define Y second
#define PB(s, x) s.push_back(x)
#define VUPPER(s,x) upper_bound(ALL(s), x) - s.begin()
#define VLOWER(s,x) lower_bound(ALL(s), x) - s.begin()
#define INS(s, x) s.insert(x)
#define FIND(s,x) s.find(x)
#define ERASE(s, x) s.erase(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define PUSH(s, x) s.push(x)
#define ALL(s) s.begin(), s.end()
#define SZ size()
#define MAXN ((int) (1e6))
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

int N, K;
vectori P;

lli fnA() {
    lli sum = 0;

    CFOR(int, i, 0, 2 * N, 2) {
        sum += abs(P[i] - P[i + 1]);
    }

    return sum;
}

lli fnB() {
    lli sum = 0;

    CFOR(int, i, 0, 2 * N, 2) {
        sum += P[i] - P[i + 1];
    }

    return abs(sum);
}


void printSolution() {
    FOR(int, i, 0, P.SZ) {
        if (i > 0) {
            cout << ' ';
        }

        cout << P[i];
    }
    cout << '\n';
}

int main() {
	optimize_io
    int a, b, c, idx;
	cin >> N >> K;

    FOR(int, i, 1, 2 * N + 1) {
        PB(P, i);
    }

    idx = P.SZ - 1;

    FOR(int, i, 0, K) {
        swap(P[idx], P[idx - 1]);
        idx -= 2;
    }

    printSolution();
	return 0;
}
