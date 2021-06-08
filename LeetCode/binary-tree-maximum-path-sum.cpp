/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define INF -1000

class Solution {
public:
    int findMaxPathSum(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return INF;
        }
        
        int leftMaxSum = 0,
            rightMaxSum = 0;
        
        int leftMaxPathSum = findMaxPathSum(root->left, leftMaxSum),
            rightMaxPathSum = findMaxPathSum(root->right, rightMaxSum);
        
        maxSum = max(maxSum, root->val + max(leftMaxSum, rightMaxSum));
        
        return max(
            root->val + leftMaxSum + rightMaxSum,
            max(
                leftMaxPathSum,
                rightMaxPathSum
            )
        );
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = 0;
        return findMaxPathSum(root, maxSum);
    }
};