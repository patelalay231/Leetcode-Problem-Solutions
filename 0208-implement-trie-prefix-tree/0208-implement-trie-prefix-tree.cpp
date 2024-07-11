#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        wordMap[word] = true;
    }
    
    bool search(string word) {
        return wordMap.find(word) != wordMap.end();
    }
    
    bool startsWith(string prefix) {
        for (const auto& entry : wordMap) {
            if (entry.first.find(prefix) == 0) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<string, bool> wordMap;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
