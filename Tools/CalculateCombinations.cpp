#include <bits/stdc++.h>
using namespace std;

int calc(int n) {
  int sum = n, i;

  if (n == 1) {
  	return 1;
  }
  
  for (i = n; i >= 1; --i) {
    sum += calc(i - 1);
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  cout << calc(n) << endl;
  return 0;
}
