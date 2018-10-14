#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 1000002
#define MOD 21092013
#define PB push_back
#define MP make_pair
#define NODE first.first
#define PARENT first.second
#define LEFT second.first
#define RIGHT second.second
#define ALL(x) x.begin(), x.end()
#define INF -1
#define L 0
#define R 1
using namespace std;
typedef stack<bool> stackbl;
typedef stack<int> stacki;
typedef vector<bool> vectorbl;

string S, T;
stackbl ParentDirections;
vectorbl ChildrenDirections;
stacki MovsLater;
bool direction;
int DP[MAXN];
int lastOccurrence[3];

inline int getIdx(char c) {
	return c == 'L' ? 0 : (c == 'R' ? 1 : 2);
}

inline char toChar(bool idx) {
	return idx ? 'R' : 'L';
}

inline bool isMovDown(char c) {
	return c == 'L' or c == 'R';
}

bool dontHaveMovUp() {
	int i, n = T.size();
	bool res = true;

	for (i = 0; i < n; ++i) {
		if (!isMovDown(T[i])) {
			res = false;
		} else {
			direction = getIdx(T[i]);

			if (! res) {
				return res;
				break;
			}
		}
	}

	return res;
}

inline int modMult(int a, int b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}

inline int modPositive(int n) {
	return ((n % MOD) + MOD) % MOD;
}

inline int modSub(int a, int b) {
	return ((a % MOD) - (b % MOD)) % MOD;
}

inline int modSum(int a, int b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}

int countDistinctSubsequences() {
	int i, n, charIdx;

	n = T.size(), DP[0] = 1;

	for (i = 1; i <= n; ++i) {
		DP[i] = modMult(2, DP[i - 1]);
		charIdx = getIdx(T[i - 1]); 

		if (lastOccurrence[charIdx] > 0) {
			DP[i] = modPositive(modSub(DP[i], DP[lastOccurrence[charIdx] - 1]));
		}

		lastOccurrence[charIdx] = i;
	}

	return DP[n];
}

void getFinalDirections() {
	int i, n = S.size();

	for (i = 0; i < n; ++i) {
		if (isMovDown(S[i])) {
			ParentDirections.push(getIdx(S[i]) ^ 1);
		} else if (! ParentDirections.empty()) {
			ParentDirections.pop();
		}
	}

	stackbl tmp(ParentDirections);

	while (!tmp.empty()) {
		ChildrenDirections.PB(tmp.top() ^ 1);
		tmp.pop();
	}

	reverse(ALL(ChildrenDirections));
}

void findMovsLater() {
	int i, n = T.size(), movs = 0;

	for (i = n - 1; i >= 0; --i) {
		if (isMovDown(T[i])) {
			++movs;
		} else {
			MovsLater.push(movs);
		}
	}

	MovsLater.push(movs);
}

int countDistinctNodes() {
	int movs, res = 0, i = 0, parentDirection;

	while ((! MovsLater.empty()) and (! ParentDirections.empty())) {
		movs = MovsLater.top();
		MovsLater.pop();

		if (i == 0) {
			res = modSum(res, modSum(movs, 1));
		} else {
			parentDirection = ParentDirections.top();
			ParentDirections.pop();

			if (parentDirection == direction) {
				res = modSum(res, movs);
			}

			res = modSum(res, 1);
		}

		++i;
	}

	return res;
}

typedef pair<int, int> Pair;
typedef pair<Pair, Pair> Tern;

vector<Tern> BT;
vector<string> Subsequences;
set<int> ans;

int createNode(int val) {
	int idx = BT.size();
	BT.PB(MP(MP(val, idx), MP(INF, INF)));
	return idx;
}

int generateTree(int node, int level) {
	if (level >= ChildrenDirections.size()) {
		return node;
	}

	bool direction = ChildrenDirections[level];

	if (direction == L) {
		int leftIdx = createNode(level + 1);
		BT[leftIdx].PARENT = node;
		BT[node].LEFT = leftIdx;
		return generateTree(leftIdx, level + 1);
	}  else {
		int rightIdx = createNode(level + 1);
		BT[rightIdx].PARENT = node;
		BT[node].RIGHT = rightIdx;
		return generateTree(rightIdx, level + 1);
	}
}

void printTree() {
	int i, n = BT.size();

	cout << "Tree: " << endl;
	for (i = 0; i < n; ++i)
		cout << setw(2) << BT[i].NODE << " ";
	cout << endl;
	for (i = 0; i < n; ++i)
		cout << setw(2) << BT[i].PARENT << " ";
	cout << endl;
	for (i = 0; i < n; ++i)
		cout << setw(2) << BT[i].LEFT << " ";
	cout << endl;
	for (i = 0; i < n; ++i)
		cout << setw(2) << BT[i].RIGHT << " ";
	cout << endl;
}

void generateAllSubsequences() {
	int i, j, n = T.size(), iter = 0;
	string s;
	set<string> heap;

	//cout << "All Subs: " << endl;
	for (i = 0; i < (1 << n); ++i) {
			s = "";

			for (j = 0; j < n; ++j) {
				if ((i & (1 << j)) > 0) {
					s += T[j];
				}
			}

			heap.insert(s);
			//cout << ">" << s << endl;
	}
	//cout << endl;

	for (set<string>::iterator it = heap.begin(); it != heap.end(); ++it) {
		Subsequences.PB((*it));
	}
}

void travel(int node, int subsequenceIdx, int level) {
	if (node != INF) {
		ans.insert(node);
	}

	if (level >= Subsequences[subsequenceIdx].size()) {
		return;
	}

	char c = Subsequences[subsequenceIdx][level];
	//cout << c << " ";

	if (c == 'U') {
		travel(BT[node].PARENT, subsequenceIdx, level + 1);
	} else if (c == 'L') {
		if (BT[node].LEFT == INF) {
			int leftIdx = createNode(BT.size());
			BT[leftIdx].PARENT = node;
			BT[node].LEFT = leftIdx;
		}

		travel(BT[node].LEFT, subsequenceIdx, level + 1);
	} else {
		if (BT[node].RIGHT == INF) {
			int rightIdx = createNode(BT.size());
			BT[rightIdx].PARENT = node;
			BT[node].RIGHT = rightIdx;
		}

		travel(BT[node].RIGHT, subsequenceIdx, level + 1);
	}
}

void findDistinctNodes(int currentNode) {
	int i, n = Subsequences.size();

	for (i = 0; i < n; ++i) {
		//cout << ">";
		travel(currentNode, i, 0);
		//cout << endl;
	}
}

int main() {
	optimize_ios

	cin >> S >> T;

	getFinalDirections();

	if (T.size() <= 20) {
		int root = createNode(0);
		int currentNode = generateTree(root, 0);
		//dd(currentNode);
		//printTree();
		generateAllSubsequences();
		findDistinctNodes(currentNode);
		/*printTree();
		cout << "Different Nodes: " << endl;
		for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
			cout << (*it) << " ";
		}
		cout << endl;*/
		cout << ans.size() << '\n';
	} else if (dontHaveMovUp()) {
		cout << countDistinctSubsequences() << '\n';
	} else {
		findMovsLater();
		cout << countDistinctNodes() << '\n';
	}
	return 0;
}
