class Solution {
public:
    vector<string> listt;

    void helper(string s, unordered_set<string>& words, int i,
                vector<string> ans) {
        if (i == s.size()) {
            string str = ans[0];
            for (int k = 1; k < ans.size(); k++) {
                str += " " + ans[k];
            }
            listt.push_back(str);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            string substr = s.substr(i, j - i + 1);
            if (words.find(substr) != words.end()) {
                ans.push_back(substr);
                helper(s, words, j + 1, ans);
                ans.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        helper(s, words, 0, {});
        return listt;
    }
};