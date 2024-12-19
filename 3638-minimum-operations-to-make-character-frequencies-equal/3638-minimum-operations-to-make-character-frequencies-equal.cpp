#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeStringGood(const string& s) {
        int n = s.size();
        int freq[26] {};
        for (char c : s) freq[c - 'a']++;

        int ans = n;
        for (int x = 1; x <= n; x++) {
            vector<vector<int>> memo(26, vector<int>(2, -1)); // Memoization table
            int result = helper(freq, 0, false, x, memo);
            ans = min(ans, result);
        }
        return ans;
    }

private:
    // Recursive function with memoization
    int helper(int freq[26], int ch, bool hasSave, int x, vector<vector<int>>& memo) {
        if (ch >= 26) return 0; // Base case: all characters processed
        
        if (memo[ch][hasSave] != -1) return memo[ch][hasSave]; // Return if already computed

        int currentFreq = freq[ch];
        int ans = INT_MAX;

        if (!hasSave) {
            if (currentFreq >= x) {
                ans = min(ans, (currentFreq - x) + helper(freq, ch + 1, true, x, memo));
            } else {
                ans = min(ans, currentFreq + helper(freq, ch + 1, true, x, memo));
                ans = min(ans, (x - currentFreq) + helper(freq, ch + 1, false, x, memo));
            }
        } else {
            if (currentFreq >= x) {
                ans = min(ans, (currentFreq - x) + helper(freq, ch + 1, true, x, memo));
            } else {
                ans = min(ans, currentFreq + helper(freq, ch + 1, true, x, memo));
                
                int save = freq[ch - 1];
                if (save >= x) save -= x;
                ans = min(ans, (x - min(currentFreq + save, x)) + helper(freq, ch + 1, false, x, memo));
            }
        }

        memo[ch][hasSave] = ans; // Store the result in memo table
        return ans;
    }
};
