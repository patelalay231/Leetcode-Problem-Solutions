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
    void helper(TreeNode* root,vector<int>& preorder){
        if(root == NULL){
            return;
        }
        preorder.push_back(root->val);
        helper(root->left,preorder);
        helper(root->right,preorder);
    }
    void flatten(TreeNode* root) {
        vector<int> preorder;
        helper(root,preorder);
        TreeNode* temp = root;
        int n = preorder.size();
        for(int i=1;i<n;i++){
            temp->left = NULL;
            temp->right = new TreeNode(preorder[i]);
            temp = temp->right;
        }
    }
};