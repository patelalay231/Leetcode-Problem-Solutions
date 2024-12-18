class Solution {
public:
    unordered_map<int, vector<string>> memo; // Memoization map

    vector<string> helper(const string& s, const unordered_set<string>& words, int start) {
        if (memo.count(start)) {
            return memo[start]; // Return cached result if available
        }

        vector<string> result;
        if (start == s.size()) {
            result.push_back(""); // Base case: empty string for valid path
            return result;
        }

        for (int end = start; end < s.size(); end++) {
            string substr = s.substr(start, end - start + 1);
            if (words.count(substr)) {
                vector<string> sublist = helper(s, words, end + 1);
                for (const string& sub : sublist) {
                    result.push_back(substr + (sub.empty() ? "" : " ") + sub);
                }
            }
        }

        memo[start] = result; // Cache the result
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return helper(s, words, 0);
    }
};
