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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root == NULL) return node;
        TreeNode* mover = root;

        while(mover){
            if(mover->val > val){
                if(mover->left == NULL){
                    mover->left = node;
                    break;
                }
                mover = mover->left;
            }
            else{
                if(mover->right == NULL){
                    mover->right = node;
                    break;
                }
                mover = mover->right;
            }
        }
        return root;
    }
};