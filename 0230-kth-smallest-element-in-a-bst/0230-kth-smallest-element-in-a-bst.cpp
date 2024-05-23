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
    void inorder(int& kthSmallest,int& cnt,TreeNode* root,int k){
        if (!root || cnt >= k) return;
        inorder(kthSmallest,cnt,root->left,k);
        cnt++;
        if(cnt == k){
            kthSmallest = root->val;
            return;
        }
        inorder(kthSmallest,cnt,root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kthSmallest = INT_MAX,cnt = 0;
        inorder(kthSmallest,cnt,root,k);
        return kthSmallest;
    }
};