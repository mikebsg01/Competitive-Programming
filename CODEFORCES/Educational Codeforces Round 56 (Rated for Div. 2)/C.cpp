#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
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
#define MAXN ((int) (1e6))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef pair<int, int> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;

lli T, N, M;
vectorlli A, B;

void printArray() {
	int i = 0;
	for (auto v : A) {
		if (i > 0) 	{
			cout << ' ';
		}
		cout << v;
		++i;
	}
	cout << '\n';
}

void findSequence() {
	lli start, l, r, idx, v, a, b, m;

	start = M - 1;
	l = start;
	r = l + 1;

	for (idx = start; idx >= 0; --idx) {
		v = B[idx];

		if (idx != start) {
			a = 0;
			b = v;

			while (a < b) {
				m = (a + b) / 2;

				if ((m > A[l + 1]) or (A[r - 1] > (v - m))) {
					b = m;
				} else {
					a = m + 1;
				}
			}

			for (m = a; m >= 0; --m) {
				if (m <= A[l + 1] and A[r - 1] <= (v - m)) {
					A[l] = m;
					A[r] = (v - m);
					break;
				}
			}
		} else {
			A[l] = (v / 2);
			A[r] = v - A[l];
		}

		--l;
		++r;	
	}
}

int main() {
	optimize_io
	int i;
	lli x;
	cin >> N;
	M = N / 2;
	A.assign(N, 0);
	for (i = 0; i < M; ++i) {
		cin >> x;
		PB(B, x);
	}
	findSequence();
	printArray();
	return 0;
}
