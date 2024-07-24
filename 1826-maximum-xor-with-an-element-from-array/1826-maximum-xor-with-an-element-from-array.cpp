class node {
public:
    node* child[2];
    node() { child[0] = child[1] = NULL; }
};
class trie {
public:
    node* root;
    trie() { root = new node(); }
    void insert(int k) {
        node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int ind = (1 << i) & k;
            ind = ind ? 1 : 0;
            if (temp->child[ind] == NULL)

                temp->child[ind] = new node();
            temp = temp->child[ind];
        }
    }
    int get(int x) {
        int ans = 0;
        node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int t = (1 << i) & x;
            t = t ? 1 : 0;
            int ind = 1 - t;
            if (temp->child[ind]) {
                ans |= 1 << i;
                temp = temp->child[ind];
            } else
                temp = temp->child[t];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& q) {
        vector<int> ans(q.size());
        sort(a.begin(), a.end());
        vector<vector<int>> v(q.size(), vector<int>(3));
        for (int i = 0; i < q.size(); i++) {
            v[i] = {q[i][1], q[i][0], i};
        }
        sort(v.begin(), v.end());
        trie obj = new trie();
        int j = 0;
        for (auto it : v) {
            int x = it[1], m = it[0], ind = it[2];
            for (; j < a.size(); j++) {
                if (a[j] <= m)
                    obj->insert(a[j]);
                else
                    break;
            }
            if (j == 0)
                ans[ind] = -1;
            else {
                int xo = obj->get(x);
                ans[ind] = xo;
            }
        }
        return ans;
    }
};