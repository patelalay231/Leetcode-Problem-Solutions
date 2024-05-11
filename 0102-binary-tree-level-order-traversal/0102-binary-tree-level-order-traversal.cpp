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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> bfs;
        if(root != NULL){
            q.push(root);
        }
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* ele  = q.front();
                q.pop();
                level.push_back(ele->val);
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
            }
            bfs.push_back(level);
        }  
        return bfs;
    }
};