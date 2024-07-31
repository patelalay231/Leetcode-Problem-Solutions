class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size(), length = 0, index = 1;
        vector<int> lps(n, 0);
        while (index < n) {
            if (s[index] == s[length]) {
                lps[index] = length + 1;
                index++;
                length++;
            } else {
                if (length == 0) {
                    index++;
                } else {
                    length = lps[length - 1];
                }
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};