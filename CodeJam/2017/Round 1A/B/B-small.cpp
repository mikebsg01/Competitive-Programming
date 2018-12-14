#include <bits/stdc++.h>
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 1002
#define MAXP 1002
#define PB push_back
#define X first
#define Y second
using namespace std;
typedef pair<int, int> Pair;

int T, 
    N, 
    P,
    ingredients[MAXN],
    packages[MAXN][MAXP],
    vis[MAXN][MAXP],
    kit[MAXN],
    ans;

bool isInRange(int portion, int grams, int packageGrams) {
  double x = (double) packageGrams,
         y = (double) portion * grams,
         a = y * 0.9,
         b = y * 1.1;
  return packageGrams >= a and packageGrams <= b;
}

bool intersects(int a, int b, int c, int d) {
  int i, j;
  if (a <= c and c <= b and b <= d) {
    return true;
  } else if (c <= a and a <= d and d <= b) {
    return true;
  }
  return false;
}

void makeKits(int idIngredient) {
  int i;

  if (idIngredient == N) {
    int packageGrams, grams, a, b, m;
    Pair limit;
    bool valid = true;

    for (i = 0; i < N; ++i) {
      packageGrams = packages[i][kit[i]];
      grams = ingredients[i];
      m = packageGrams / grams;
      if (isInRange(m,  grams, packageGrams) or isInRange(m + 1, grams, packageGrams)) {
        a = isInRange(m,  grams, packageGrams) ? m : m + 1;
        b = a;
        while (isInRange(a,  grams, packageGrams)) {
          --a;
        }
        a = a + 1;
        while (isInRange(b,  grams, packageGrams)) {
          ++b;
        }
        b = b - 1;
        if (i) {
          if (!intersects(a, b, limit.X, limit.Y)) {
            valid = false;
            break;
          }
        } else {
          limit.X = a;
          limit.Y = b;
        }
      } else {
        valid = false;
        break;
      }
    }
    if (valid) {
      ++ans;

      for (i = 0; i < N; ++i) {
        vis[i][kit[i]] = true;
      }
    }
    return;
  }

  for (i = 0; i < P; ++i) {
    if (!vis[idIngredient][i]) {
      kit[idIngredient] = i;
      makeKits(idIngredient + 1);
      kit[idIngredient] = 0;
    }
  }
}

int main() {
  optimize_ios
  int i, j, k, x;
  cin >> T;
  for (i = 0; i < T; ++i) {
    cin >> N >> P;
    for (j = 0; j < N; ++j) {
      cin >> ingredients[j];
    }
    ans = 0;
    for (j = 0; j < N; ++j) {
      for (k = 0; k < P; ++k) {
        cin >> x;
        packages[j][k] = x;
      }
    }
    makeKits(0);
    cout << "Case #" << (i + 1) << ": " << ans << "\n";
    memset(vis, 0, sizeof(vis));
  }
  return 0;
}