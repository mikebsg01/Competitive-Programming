#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, K;

pair<int,int> simulate() {
  int i, tmp;
  priority_queue<int> PQ;
  pair<int, int> P;

  PQ.push(N);

  for (i = 0; i < K; ++i) {
    tmp = PQ.top() - 1;
    PQ.pop();
    P.Y = tmp / 2;
    P.X = tmp - P.Y;
    // cout << P.X << " " << P.Y << endl;
    PQ.push(P.X);
    PQ.push(P.Y);
  }
  return P;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T, i;
  pair<int, int> ans;
  cin >> T;

  for (i = 1; i <= T; ++i) {
    cin >> N >> K;
    ans = simulate();
    cout << "Case #" << i << ": " << ans.X << " " << ans.Y << "\n";
  }
  return 0;
}