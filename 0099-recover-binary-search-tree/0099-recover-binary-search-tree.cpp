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
    vector<int> inorder;
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left); // Visit left subtree
        inorder.push_back(root->val); // Visit node itself
        inorderTraversal(root->right); // Visit right subtree
    }

    void correctBst(TreeNode* root, const std::vector<int>& inorder, int& i) {
    if (root == NULL || i == inorder.size()) {
        return;
    }
    correctBst(root->left, inorder, i);
    if (root->val != inorder[i]) {
        root->val = inorder[i];
    }
    i++;
    correctBst(root->right, inorder, i);
}


    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        sort(inorder.begin(),inorder.end());
        int i = 0;
        correctBst(root,inorder,i);
    }
};