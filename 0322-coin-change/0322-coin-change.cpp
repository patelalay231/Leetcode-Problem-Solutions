class Solution {
public:
    int helper(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (i == 0) {
            if (amount % coins[0])
                return 1e9;
            return (amount / coins[0]);
        }
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int not_take = helper(coins, i - 1, amount, dp);
        int take = 1e9;
        if (coins[i] <= amount) {
            take = 1 + helper(coins, i, amount - coins[i], dp);
        }
        return dp[i][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        for (int tar = 0; tar <= amount; tar++) {
            if (tar % coins[0] == 0)
                dp[0][tar] = tar / coins[0];
            else
                dp[0][tar] = 1e9;
        }
        for (int i = 1; i < n; i++) {
            for (int tar = 0; tar <= amount; tar++) {
                int not_take = dp[i - 1][tar];
                int take = 1e9;
                if (coins[i] <= tar) {
                    take = 1 + dp[i][tar - coins[i]];
                }
                dp[i][tar] = min(take, not_take);
            }
        }
        if(dp[n - 1][amount] == 1e9) return -1;
        return dp[n - 1][amount];
    }
};