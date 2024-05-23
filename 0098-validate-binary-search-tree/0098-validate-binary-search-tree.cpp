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
    void inorder(TreeNode* root,vector<int> & inorderArr){
        if(root == NULL){
            return;
        }
        inorder(root->left,inorderArr);
        inorderArr.push_back(root->val);
        inorder(root->right,inorderArr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorderArr;
        inorder(root,inorderArr);
        int n = inorderArr.size();
        for(int i=0;i<n-1;i++){
            if(inorderArr[i] >= inorderArr[i+1]){
                return false;
            }
        }
        return true;
    }
};