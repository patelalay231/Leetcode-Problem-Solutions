class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0; // No valid decodings for an empty string or string starting with '0'

        vector<int> dp(n + 1, 0);
        dp[n] = 1; // Base case: 1 way to decode an empty suffix
        
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0; // Leading zero cannot be decoded
            } else {
                dp[i] = dp[i + 1]; // Single digit decode
                
                if (i + 1 < n) { // Two-digit decode
                    int sub = stoi(s.substr(i, 2));
                    if (sub <= 26) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0]; // The answer for the full string
    }
};
