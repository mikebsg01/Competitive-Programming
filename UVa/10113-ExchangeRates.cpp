#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define MAXN 62
#define INF -1
#define PB push_back
#define MP make_pair
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> T;
typedef map<string, int> M;

M VertexId; int id = 0;
vector<T> E[MAXN];
bitset<MAXN> vis;
P ans;
bool solved;
int memo[MAXN][MAXN][2];

string toLowerCase(string s) {
	int n = s.size(), i;
	string t("");

	for (i = 0; i < n; ++i) {
		t += tolower(s[i]);
	}

	return t;
}

int getVertexId(string s) {
	M::iterator it = VertexId.find(s);

	if (it != VertexId.end()) {
		return it->second;
	}

	return VertexId[s] = id++;
}

string getVal(int n) {
	stringstream ss;

	if (solved) {
		ss << n;
		return ss.str();
	}

	ss << '?';
	return ss.str();
}

void dfs(int sId, int tId, int numerator, int denominator) {
	if (solved or vis[sId]) {
		return;
	} else if (sId == tId) {
		ans.X = numerator;
		ans.Y = denominator;
		solved = true;
		return;
	}

	int i, n, num, denom, mcd;

	vis[sId] = true;
	n = E[sId].size();

	for (i = 0; i < n; ++i) {
		num = numerator * E[sId][i].X.Y;
		denom = denominator * E[sId][i].X.X;
		mcd = __gcd(num, denom);
		num /= mcd;
		denom /= mcd;
		dfs(E[sId][i].Y, tId, num, denom);
	}
}

int main() {
	optimize_ios

	char c;
	int x, xId, y, yId;
	string xs, ys;

	while ((cin >> c) and c != '.') {
		if (c == '!') {
			cin >> x >> xs >> c >> y >> ys;

			xs = toLowerCase(xs);
			ys = toLowerCase(ys);

			xId = getVertexId(xs);
			yId = getVertexId(ys);

			E[xId].PB(MP(MP(x, y), yId));
			E[yId].PB(MP(MP(y, x), xId));

			memo[xId][xId][0] = memo[yId][yId][0] = 1;
			memo[xId][xId][1] = memo[yId][yId][1] = 1;
		} else {
			cin >> xs >> c >> ys;

			xs = toLowerCase(xs);
			ys = toLowerCase(ys);

			xId = getVertexId(xs);
			yId = getVertexId(ys);

			if (memo[xId][yId][0] > 0 and memo[xId][yId][1] > 0) {
				ans.X = memo[xId][yId][0];
				ans.Y = memo[xId][yId][1];
			} else {
				ans.X = ans.Y = INF;
				solved = false;
				dfs(xId, yId, 1, 1);

				if (solved) {
	                                memo[xId][yId][0] = memo[yId][xId][1] = ans.X;
                                	memo[xId][yId][1] = memo[yId][xId][0] = ans.Y;
                        	}
			}

			cout << getVal(ans.Y) << ' ' << xs << " = " << getVal(ans.X) << ' ' << ys << '\n';
			
			vis.reset();
		}
	}
	return 0;
}
