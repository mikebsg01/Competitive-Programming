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
class Solution {
public:
    int getSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftChildSum = getSum(root->left);
        int rightChildSum = getSum(root->right);
        return root->val + leftChildSum + rightChildSum;
    }
    
    void updateTree(TreeNode* root, int& sum) {
        if (root == NULL) {
            return;
        }
        
        updateTree(root->left, sum);

        int t = root->val;
        root->val = sum;
        sum -= t;

        updateTree(root->right, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = getSum(root);
        updateTree(root, sum);
        return root;
    }
};