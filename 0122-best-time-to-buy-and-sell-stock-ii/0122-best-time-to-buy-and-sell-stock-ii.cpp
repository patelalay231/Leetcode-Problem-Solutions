class Solution {
public:
    int helper(vector<int>& prices,int i,bool canBuy,vector<vector<int>>& dp){
        if(i == prices.size()){
            return 0;
        }
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        if(canBuy){
            int take = -prices[i] + helper(prices,i+1,0,dp);
            int not_take = 0 + helper(prices,i+1,1,dp);
            return dp[i][canBuy] = max(take,not_take);
        }
        else{
            int sell = prices[i] + helper(prices,i+1,1,dp);
            int not_sell = 0 + helper(prices,i+1,0,dp);
            return dp[i][canBuy] = max(sell,not_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,0,1,dp);   
    }
};