class Solution {
public:
    bool helper(vector<int>& nums,int i,int sum,int rem,vector<vector<int>>& dp){
        if(sum == rem){
            return true;
        }
        if(i == nums.size()-1){
            return sum == rem;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = helper(nums,i+1,sum+nums[i],rem-nums[i],dp);
        bool notTake = helper(nums,i+1,sum,rem,dp);
        return dp[i][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(n,vector<int>(sum,-1));
        return helper(nums,0,0,sum,dp);
    }
};