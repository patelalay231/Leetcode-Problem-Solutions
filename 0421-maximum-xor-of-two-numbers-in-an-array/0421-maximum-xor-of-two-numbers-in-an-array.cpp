class Node {

public:
    Node* link[2];
    bool containsKey(int val) { return (link[val]); }
    Node* get(int val) { return link[val]; }
    void put(Node* node, int val) { link[val] = node; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }
    void insert(int val) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(new Node(), bit);
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit)) {
                maxNum |= (1 << i);
                node = node->get(!bit);

            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (auto& it : nums) {
            trie.insert(it);
        }
        int mx = 0;
        for (auto& it : nums) {
            mx = max(mx, trie.getMax(it));
        }
        return mx;
    }
};