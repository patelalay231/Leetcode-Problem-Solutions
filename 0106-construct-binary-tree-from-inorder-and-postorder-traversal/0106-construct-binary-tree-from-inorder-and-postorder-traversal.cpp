/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root =
            buildTree(postorder, inorder, 0, n - 1, 0, n - 1, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder,
                        int poStart, int poEnd, int inStart, int inEnd,
                        unordered_map<int, int>& inMap) {
        if (inStart > inEnd || poStart > poEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[poEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left =
            buildTree(postorder, inorder, poStart, poStart + numsLeft - 1,
                      inStart, inStart + numsLeft, inMap);
        root->right = buildTree(postorder, inorder, poStart + numsLeft,
                                poEnd - 1, inRoot + 1, inEnd, inMap);

        return root;
    }
};