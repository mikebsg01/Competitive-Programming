#include <iostream>
#include <vector>
#include <algorithm>
#define dd(x) cout << #x << ": " << x << endl;
#define UNVISITED -1
using namespace std;

string s;

int longestSubstring(const string& s) {
    int n = s.size(), i, c, pos, currentLength = 0, maxLength = 0;
    vector<int> visited(26, UNVISITED);

    for (i = 0; i < n; ++i) {
        c = s[i] - 'a';
        pos = visited[c];

        if (pos == UNVISITED) {
            ++currentLength;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = i - pos;
        }

        visited[c] = i;
    }

    return maxLength = max(maxLength, currentLength);
}

int main() {
    cin >> s;
    cout << longestSubstring(s) << '\n';
    return 0;
}