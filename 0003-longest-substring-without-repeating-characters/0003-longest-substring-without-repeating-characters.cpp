class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.length();
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        while (j < n) {
            if (mp.find(s[j]) != mp.end()) {
                while (i < j && s[i] != s[j]) {
                    mp.erase(s[i]);
                    i++;
                }
                mp.erase(s[i]);
                i++;
            }
            mp[s[j]] = 1;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};