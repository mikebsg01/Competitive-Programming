#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <deque>
#define ALL(s) s.begin(), s.end()
#define VUPPER(s,x) upper_bound(ALL(s), x) - s.begin()
using namespace std;

int solution(vector<int> A) {
  int n = A.size();
  vector<int> LIS;

  for (int i = 0; i < n; ++i) {
    int x = A[i],
        pos = VUPPER(LIS, x),
        m = LIS.size();
    
    if (pos < m) {
       LIS[pos] = x;
    } else {
       LIS.push_back(x);
    }
  }
  
  return LIS.size(); 
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
  vector<int> A = toIntVector(AS);
  cout << solution(A);
}