struct Node {
    Node* links[2];
    int n = 0;
    bool contain(int bit) { return links[bit]; }
    void put(int bit, Node* node) { links[bit] = node; }
    Node* get(int bit) { return links[bit]; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }
    void insert(bitset<32>& bits, int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int x = 0;
            if (bits[i])
                x = 1;
            if (!node->contain(x))
                node->put(x, new Node());
            node = node->get(x);
        }
        node->n = num;
    }
    int findxor(bitset<32>& bits, int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int x = 1, y = 0;
            if (bits[i]) {
                x = 0;
                y = 1;
            }
            if (node->contain(x)) {
                node = node->links[x];
                continue;
            }
            node = node->links[y];
        }
        return num ^ (node->n);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            bitset<32> seti(nums[i]);
            trie.insert(seti, nums[i]);
        }
        for (int i = 0; i < n; i++) {
            bitset<32> seti(nums[i]);
            ans = max(ans, trie.findxor(seti, nums[i]));
        }
        return ans;
    }
};