class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr; // Move the current row to previous for the next iteration
        }
        int lcs = prev[m]; // Length of longest common subsequence
        int ans = n + m - 2 * lcs; // Minimum steps to convert word1 to word2
        return ans;
    }
};
