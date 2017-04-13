#include <bits/stdc++.h>
using namespace std;

int T, N, K;
string S;

int flips(int pos, int take) {
  int n, m, i;

  if (pos + take > N) {
    return 0;
  }

  m = take - K;
  n = take - (2 * m);

  if (m == 0) {
    for (i = pos; i < pos + K; ++i) {
      if (S[i] == '+') {
        return 0;
      }
    }
    for (i = pos; i < pos + K; ++i) {
      S[i] = '+';
    }
    return 1;
  }

  for (i = pos; i < pos + m; ++i) {
    if (S[i] == '+') {
      return 0;
    }
  }

  for (i = pos + m; i < pos + m + n; ++i) {
    if (S[i] ==  '-') {
      return 0;
    }
  }

  for (i = pos + m + n; i < pos + take; ++i) {
    if (S[i] == '+') {
      return 0;
    }
  }

  for (i = pos; i < pos + take; ++i) {
    S[i] = '+';
  }

  return 2;
}

int flipper() {
  int n, i, j, ans = 0;
  n = S.size();

  for (i = 0; i < N - K + 1; ++i) {
    for (j = 2 * K - 1; j >= K; --j) {
      ans += flips(i, j);
    }
  }
  return ans;
}

int main() {
  int n, i, j, ans;
  bool isImpossible;
  cin >> T;
  for (i = 0; i < T; ++i) {
    cin >> S >> K;
    N = S.size();
    ans = flipper();
    cout << "Case #" << (i + 1) << ": ";
    isImpossible = false;

    for (j = 0; j < N; ++j) {
      if (S[i] == '-') {
        cout << "IMPOSSIBLE" << "\n";
        isImpossible = true;
        break;
      }
    }

    if (!isImpossible) {
      cout << ans << "\n";
    }
  }
  return 0;
}