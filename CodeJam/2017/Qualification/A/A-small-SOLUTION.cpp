#include <bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define INF -1
using namespace std;

int it = 0;

typedef struct Three {
  int next;
  int level;
  string s;
} Three;

inline bool isCorrect(string s) {
  int i;
  for (i = 0; i < s.size(); ++i) {
    ++it;
    if (s[i] == '-') {
      return false;
    }
  }
  return true;
}

int BFS(string S, int K) {
  int N, i, j;
  Three tmp =  { .next = 0, .level = 0, .s = S };
  queue<Three> Q;

  int x = 0;
  N = S.size();
  Q.push(tmp);

  while (!Q.empty()) {
    tmp = Q.front();
    Q.pop();

    if (isCorrect(tmp.s)) {
      return tmp.level;
    }

    for (i = tmp.next; i < N - K + 1; ++i) {
      for (j = i; j < i + K; ++j) {
        tmp.s[j] = tmp.s[j] == '+' ? '-' : '+';
      }
      Three tmp2 = { .next = i + 1, .level = tmp.level + 1, .s = tmp.s };
      Q.push(tmp2);
      for (j = i; j < i + K; ++j) {
        tmp.s[j] = tmp.s[j] == '+' ? '-' : '+';
      }
    }
    ++it;
  }
  return INF;
}

int main() {
  int T, K, i, ans;
  string S;
  cin >> T;
  for (i = 0; i < T; ++i) {
    cin >> S >> K;
    ans = BFS(S, K);
    cout << "Case #" << (i + 1) << ": ";
    if (ans != INF) {
      cout << ans << "\n";
    } else {
      cout << "IMPOSSIBLE" << "\n";
    }
  }
  // cout << "Iterations: " << it << endl;
  return 0;
}