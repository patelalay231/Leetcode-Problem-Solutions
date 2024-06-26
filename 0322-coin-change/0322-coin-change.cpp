class Solution {
public:
    int helper(vector<int>& coins, int i,int amount,vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(i == 0){
            if(amount % coins[0]) return 1e9;
            return (amount / coins[0]);
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int not_take = helper(coins,i-1,amount,dp);
        int take = 1e9;
        if(coins[i] <= amount){
            take = 1 + helper(coins,i,amount - coins[i],dp);
        }
        return dp[i][amount] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1, -1));
        int ans = helper(coins,n-1,amount,dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};