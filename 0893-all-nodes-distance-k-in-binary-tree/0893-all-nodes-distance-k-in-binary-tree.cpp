/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> ans;

                    //FINDING PARENTS
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->left) {
            parent[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right) {
            parent[temp->right] = temp;
            q.push(temp->right);
        }
    }

                        //BFS TRAVERSAL
    q.push(target);
    map<TreeNode*, bool> vis;    //map for visiting node
    vis[target] = true;         
    while (k--) {
        int siz = q.size();
        while (siz--) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left && !vis[temp->left]) {
                vis[temp->left] = true;
                q.push(temp->left);
            }
            if (temp->right && !vis[temp->right]) {
                vis[temp->right] = true;
                q.push(temp->right);
            }
            if (parent[temp] != NULL && !vis[parent[temp]]) {
                vis[parent[temp]] = true;
                q.push(parent[temp]);
            }
        }
    }

   
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        ans.push_back(temp->val);
    }

    return ans;
    }
};