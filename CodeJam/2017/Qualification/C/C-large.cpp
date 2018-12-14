#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long lli;

lli N, K;

pair<lli, lli> simulate() {
  pair<lli, lli> P;
  lli pot = 2,
      level = 1;

  while (K >= pot) {
    pot *= 2;
    ++level;
  }

  if (pot > N) {
    P.X = P.Y = 0;
    return P;
  }

  if (K == (pot / 2)) {
    P.X = P.Y = N / pot;
    P.Y = P.Y - 1;
  } else {
    P.X = P.Y = ((int)(N / pot)) - 1;
  }

  // cout << "pot: " << pot << " level: "  << level << endl;
  return P;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pair<lli, lli> ans;
  int T, i;

  cin >> T;

  for (i = 1; i <= T; ++i) {
    cin >> N >> K;
    ans = simulate();
    cout << "Case #" << i << ": " << ans.X << " " << ans.Y << "\n";
  }
  return 0;
}