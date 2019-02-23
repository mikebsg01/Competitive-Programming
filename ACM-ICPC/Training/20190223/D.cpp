#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,b,a) for (int i = (b - 1); i >= a; --i)
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
#define MAXN 22
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
typedef set<Pair> setPair;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;
typedef map<string, string> dict;
typedef map<string, int> cmap;
typedef priority_queue<int> pqi;
typedef priority_queue<lli> pqlli;
typedef priority_queue<Pair> pqPair;

int N, M;
string A[MAXN];
dict trans;
cmap match[2];
ulli incorrectTrans, correctTrans = 1, totalTrans = 1;

void calcTranslations() {
	int correct, matches;
	FOR(i, 0, N) {
		correct = match[1][A[i]];
		correctTrans *= correct;
		matches = match[0][A[i]] + correct;
		totalTrans *= matches;
	}
}

string translate() {
	string t("");
	FOR(i, 0, N) {
		if (i > 0) {
			t += ' ';
		}

		t += trans[A[i]];
	}
	return t;
}

int main() {
	optimize_io
	string d, e, c;
	cin >> N;

	FOR(i, 0, N) {
		cin >> A[i];
	}

	cin >> M;

	FOR(i, 0, M) {
		cin >> d >> e >> c;
		trans[d] = e;
		match[c == "correct"][d] += 1;
	}

	calcTranslations();

	if (totalTrans == 1) {
		cout << translate() << ((correctTrans == 1) ? "\ncorrect\n" : "\nincorrect\n");
	} else {
		incorrectTrans = totalTrans - correctTrans;
		cout << correctTrans << " correct\n" << incorrectTrans << " incorrect\n";
	}
	return 0;
}
