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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        int n = inorder.size();

        for(int i=0;i<n;i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder,inorder,0,n-1,0,n-1,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd, unordered_map<int,int>& inMap){
        if(inStart > inEnd || preStart > preEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder,inorder,preStart + 1,preStart + numsLeft , inStart ,inRoot - 1,inMap);
        root->right = buildTree(preorder,inorder,preStart + numsLeft + 1,preEnd, inRoot + 1,inEnd,inMap);

        return root;
    }
};