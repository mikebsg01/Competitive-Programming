class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        char c;
        bool isPrefix = true;
        string ans("");

        for (int i = 0; i < m; ++i) {
            c = strs[0][i];

            for (int j = 1; j < n; ++j) {
                if (c != strs[j][i]) {
                    isPrefix = false;
                    break;
                }
            }

            if (!isPrefix) {
                break;
            }

            ans += c;
        }

        return ans;
    }
};