class Solution {
public:
    int solve(int i,int buy, int k,vector<int>&prices,vector<vector <vector<int>>>&dp)
    {
        int profit = 0;
        if(i == prices.size() || k == 0) return  0;
       if(dp[i][buy][k] != -1)  return dp[i][buy][k];

       if(buy) 
         profit = max(-prices[i] + solve(i+1,0,k,prices,dp),solve(i+1,1,k,prices,dp));
         else
           profit = max(prices[i] + solve(i+1,1,k-1,prices,dp),solve(i+1,0,k,prices,dp));

           return dp[i][buy][k] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};