class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), k = t.length(), minIdx = -1, mini = INT_MAX, cnt = 0;
        if (k > n)
            return "";
        vector<int> hash(126, 0);
        for (char c : t) {
            hash[c]++;
        }
        int l = 0, r = 0;
        string sub;
        while (r < n) {
            if (hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;
            while (cnt == k) {
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                int len = r - l + 1;
                if (mini > len) {
                    mini = len;
                    minIdx = l;
                }
                l++;
            }
            r++;
        }
        return minIdx == -1 ? "" : s.substr(minIdx, mini);
    }
};