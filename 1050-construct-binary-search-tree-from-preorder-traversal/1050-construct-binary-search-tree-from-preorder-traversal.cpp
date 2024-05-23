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

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(INT_MAX,i,preorder);
    }
    TreeNode* buildBST(int ub,int& i,vector<int>& preorder){
        if(i == preorder.size() || preorder[i] > ub) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = buildBST(root->val,i,preorder);
        root->right = buildBST(ub,i,preorder);
        return root;
    }
};