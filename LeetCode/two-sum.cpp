#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, 0);
        unordered_map<int, int> dict;

        for (int i = 0; i < nums.size(); ++i) {
            int current = nums[i],
                x = target - current;

            if (dict.count(x) > 0) {
                ans[1] = i;
                ans[0] = dict[x];
                break;
            } else {
                dict[current] = i;
            }
        }
        
        return ans;
    }
};