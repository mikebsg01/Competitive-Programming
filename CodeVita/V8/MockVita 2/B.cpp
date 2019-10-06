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
#define MAXN ((int) (500+5))
#define EPS (1e-8)
#define INF -1
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> Pair;
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

int N;
string A[MAXN], B[MAXN];
mapi maxPairs;

inline int charToInt(char c) {
    return ((int)(c - '0'));
}

inline char intToChar(int n) {
    return ((char)(n + '0'));
}

string intToStr(int num) {
    string t("");

    while (num > 0) {
        t = intToChar(num % 10) + t;
        num /= 10;
    }

    return t;
}

Pair digits(string s) {
    int x;
    Pair t(-1, 9999);

    FOR(ui, i, 0, s.SZ) {
        x = charToInt(s[i]);
        t.X = max(t.X, x);
        t.Y = min(t.Y, x);
    }

    return t;
}

int calcPairs(int equals) {
    if (equals < 2) return 0;
    else if (equals == 2) return 1;
    return 2;
}

int solve() {
    char a;
    int equals, ans = 0;

    FOR(ui, i, 0, 10) {
        a = intToChar(i);

        equals = 0;
        CFOR(int, j, 0, N, 2) {
            if (B[j][0] == a) {
                ++equals;
            }
        }

        maxPairs[i] = calcPairs(equals);

        equals = 0;
        CFOR(int, j, 1, N, 2) {
            if (B[j][0] == a) {
                ++equals;
            }
        }

        maxPairs[i] = max(maxPairs[i], calcPairs(equals));
        ans += maxPairs[i];
    }

    return ans;
}

int main() {
	optimize_io
    int x;
    Pair t;
    string s;
    cin >> N;

    FOR(int, i, 0, N) {
        cin >> A[i];
        t = digits(A[i]);
        x = (11 * t.X) + (7 * t.Y);
        s = intToStr(x);
        s = (s.SZ > 2) ? s.substr(1, 2) : s;
        B[i] = s;
    } 

    cout << solve() << '\n';
	return 0;
}
