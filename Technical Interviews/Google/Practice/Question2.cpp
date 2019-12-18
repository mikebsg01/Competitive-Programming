#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <set>
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define MAXN 1002
#define MAXSUM 100002
#define UNVISITED -1
using namespace std;

bool DP[MAXN][MAXSUM];
set<int> S;

void dp(vector<int>& A, int sum, int idx) {
    if (idx == A.size() or DP[idx][sum]) {
        return;
    }

    DP[idx][sum] = true;
    S.insert(sum);
    dp(A, sum + A[idx], idx + 1),
    dp(A, sum, idx + 1);
}

int solution(vector<int> A) {
    int half, N = A.size(), totalSum = 0;
    set<int>::iterator it;

    FOR(int, i, 0, N) {
        totalSum += A[i];
    }

    dp(A, 0, 0);
    half = totalSum / 2;
    it = S.lower_bound(half);
    return abs(2 * (*it) - totalSum);
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  cout << solution(toIntVector(AS));
}