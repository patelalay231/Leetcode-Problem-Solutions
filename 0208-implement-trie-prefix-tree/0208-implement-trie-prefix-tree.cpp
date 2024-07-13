#include <iostream>
using namespace std;

class Trie {
private:
    struct Node {
        Node* links[26];
        bool flag;
        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = NULL;
            }
            flag = false; // Initialize flag
        }
    };
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* mover = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if (mover->links[word[i] - 'a'] == NULL) {
                mover->links[word[i] - 'a'] = new Node();
            }
            mover = mover->links[word[i] - 'a'];
        }
        mover->flag = true; // Mark the end of the word
    }

    bool search(string word) {
        int n = word.length();
        Node* mover = root;
        for (int i = 0; i < n; i++) {
            if (mover->links[word[i] - 'a'] == NULL) {
                return false;
            }
            mover = mover->links[word[i] - 'a'];
        }
        return mover->flag;
    }

    bool startsWith(string prefix) {
        int n = prefix.length();
        Node* mover = root;
        for (int i = 0; i < n; i++) {
            if (mover->links[prefix[i] - 'a'] == NULL) {
                return false;
            }
            mover = mover->links[prefix[i] - 'a'];
        }
        return true;
    }
};