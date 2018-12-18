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
#define WORD second.first
#define ID second.second
#define MAXN ((int) (1e6))
#define EPS (1e-8)
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef vector<string> vectorstr;
typedef pair<string, int> Pair;
typedef pair<int, Pair> Tern;
typedef pair<Pair, Pair> Quart;
typedef vector<Pair> vectorPair;
typedef set<lli> setlli;
typedef set<string> setstr;
typedef set<Pair> setPair;
typedef set<Tern> setTern;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;

lli T, N, M;
setTern cs;
setstr words;
map<int, char> ans;

bool overlap(string a, string b, string& word) {
	for (int i = 1; i < (N - 1); ++i) {
		if (a[i] != b[i - 1]) {
			return false;
		}
	}

	word = a + b[b.size() - 1];
	return true;
}

void findWord() {
	setTern::iterator it = cs.begin(), ita, itb;
	string t;

	ita = setTern::iterator(it);
	itb = next(it, 1);

	if (overlap((*ita).WORD, (*itb).WORD, t)) {
		INS(words, t);
	}

	if (overlap((*itb).WORD, (*ita).WORD, t)) {
		INS(words, t);
	}
}

bool match(string word, string a, string b) {
	int n = word.size();
	for (int i = 0, m = a.size(); i < m; ++i) {
		if (word[i] != a[i]) {
			return false;
		}

		if (word[n - i - 1] != b[m - i - 1]) {
			return false;
		}
	}
	return true;
}

bool findMatches(string word) {
	setTern::iterator it, ita, itb;

	for (it = cs.begin(); it != cs.end(); advance(it, 2)) {
		ita = setTern::iterator(it);
		itb = next(it, 1);

		if (match(word, (*ita).WORD, (*itb).WORD)) {
			ans[(*ita).ID] = 'P';
			ans[(*itb).ID] = 'S';
		} else if (match(word, (*itb).WORD, (*ita).WORD)) {
			ans[(*ita).ID] = 'S';
			ans[(*itb).ID] = 'P';
		} else {
			return false;
		}
	}

	return true;
}

void findSolution() {
	for (setstr::iterator it = words.begin(); it != words.end(); ++it) {
		if (findMatches((*it))) {
			break;
		}
		ans.clear();
	}
}

int main() {
	optimize_io
	int i;
	string s;
	cin >> N;
	M = 2 * N - 2;

	for (i = 0; i < M; ++i) {
		cin >> s;
		INS(cs, MP(-1 * s.size(), MP(s, i)));
	}

	if (M != 2) {
		findWord();
		findSolution();

		for (i = 0; i < M; ++i) {
			cout << ans[i];
		}
		cout << '\n';
	} else {
		cout << "PS\n";
	}
	return 0;
}
