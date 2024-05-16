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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;  // An empty tree is symmetric
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;  // Both subtrees are empty
        if (!left || !right) return false; // One of the subtrees is empty, not symmetric
        if (left->val != right->val) return false; // Values at the nodes do not match

        // Recursively check for symmetry: left's left vs right's right and left's right vs right's left
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
