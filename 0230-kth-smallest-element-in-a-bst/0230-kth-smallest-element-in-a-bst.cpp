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
    void solve(priority_queue<int, vector<int>, greater<int>>& pq,TreeNode* root){
        if(root == NULL){
            return;
        }
        pq.push(root->val);
        solve(pq,root->right);
        solve(pq,root->left);
    }
    int kthSmallest(TreeNode* root, int k) {    
        priority_queue<int, vector<int>, greater<int>> pq;
        solve(pq,root);
        while(k!=1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};