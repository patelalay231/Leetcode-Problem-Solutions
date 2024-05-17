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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int res = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int left = 0,right = 0;
            for(int i=0;i<size;i++){
                TreeNode* ele = q.front().first;
                long curr_id = q.front().second - mini;
                if(i == 0) left = curr_id;
                if(i == size-1) right = curr_id;
                q.pop();
                if(ele->left){
                    q.push({ele->left,2*curr_id+1});
                }
                if(ele->right){
                    q.push({ele->right,2*curr_id+2});
                }
            }
            res = max(res,right - left + 1);
        }
        return res;
    }
};