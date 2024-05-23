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
    TreeNode* makeBst(vector<int>& preorder, int pstart, int pend,
                      vector<int>& inorder, int instart, int inend,
                      unordered_map<int, int>& inMap) {

        if (pstart > pend || instart > inend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[pstart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - instart;
        root->left = makeBst(preorder, pstart + 1, pstart + numsLeft, inorder,
                             instart, inRoot-1, inMap);
        root->right = makeBst(preorder, pstart + numsLeft + 1, pend, inorder,
                              inRoot+1, inend, inMap);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) {
            return NULL;
        }
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = makeBst(preorder, 0, n - 1, inorder, 0, n - 1, inMap);

        return root;
    }
};