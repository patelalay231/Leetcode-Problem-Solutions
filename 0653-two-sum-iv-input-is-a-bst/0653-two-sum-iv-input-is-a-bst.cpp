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
    
    bool solve(TreeNode* root,int k ,unordered_set<int>& mp){
        int rem = k-(root->val);
        if(mp.find(rem) != mp.end()){
            return true;
        }
        mp.insert(root->val);
        bool left=false,right=false;
        if(root->left) left = solve(root->left,k,mp);
        if(root->right) right = solve(root->right,k,mp);
        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        unordered_set<int> mp;
        return solve(root,k,mp);
    }
};