class Solution {
public:
    int helper(vector<int>& prices, int canBuy, int cooldown, int i, vector<vector<vector<int>>>& dp) {
        if (i >= prices.size()) return 0; // Base case: end of prices array

        if (dp[i][canBuy][cooldown] != -1) return dp[i][canBuy][cooldown]; // Use memoized result

        if (cooldown > 0) {
            return dp[i][canBuy][cooldown] = helper(prices, canBuy, cooldown - 1, i + 1, dp); // Skip the day due to cooldown
        }

        if (canBuy) {
            int bought = -prices[i] + helper(prices, 0, 0, i + 1, dp); // Buy stock
            int not_bought = 0 + helper(prices, 1, 0, i + 1, dp); // Don't buy stock
            return dp[i][canBuy][cooldown] = max(bought, not_bought);
        } else {
            int sell = prices[i] + helper(prices, 1, 1, i + 1, dp); // Sell stock and activate cooldown
            int not_sell = 0 + helper(prices, 0, 0, i + 1, dp); // Don't sell stock
            return dp[i][canBuy][cooldown] = max(sell, not_sell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1))); // Initialize DP table
        return helper(prices, 1, 0, 0, dp);
    }
};
