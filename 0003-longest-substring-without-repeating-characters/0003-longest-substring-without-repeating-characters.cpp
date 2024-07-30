class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.length();
        int i = 0, j = 0;
        vector<int> ele(128,-1);
        while (j < n) {
            if (ele[s[j]] != -1) {
                i = max(i,ele[s[j]] + 1);
            }
            ele[s[j]] = j;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};