/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxi = INT_MIN;
    int maximumSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftS = max(0,maximumSum(root->left));
        int rightS = max(0,maximumSum(root->right));
        maxi = max(maxi, root->val + leftS + rightS);
        return root->val + max(leftS, rightS);
    }
    int maxPathSum(TreeNode* root) {
        int ans = maximumSum(root);
        return maxi;
    }
};