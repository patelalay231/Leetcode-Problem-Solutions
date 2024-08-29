class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int i = 0;
        string revS;
        while (i < len) {
            while (i < len && s[i] == ' ') i++;  // Skip spaces
            string temp;
            while (i < len && s[i] != ' ') temp += s[i++];  // Collect word
            if (!temp.empty()) revS = temp + (revS.empty() ? "" : " ") + revS;
        }
        return revS;
    }
};
