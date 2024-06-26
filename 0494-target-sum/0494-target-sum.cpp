class Solution {
public:
    // isko solve karna hai iss question ki tarah 
    // https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos
    int solve(vector<int> &nums, int target, int i, vector<vector<int>> &dp){
    if(i == 0){
        if(target==0 && nums[0]==0)
            return 2;
        if(target==0 || target == nums[0])
            return 1;
        return 0;
    }
    if(dp[i][target] != -1){
        return dp[i][target];
    }

    int noPick = solve(nums, target, i-1, dp);

    int Pick = 0;
    if(nums[i] <= target){
        Pick = solve(nums, target - nums[i], i-1, dp);
    }

    return dp[i][target] = (Pick+noPick);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total-target<0 || (total - target)%2==1){
            return 0;
        }

        int nT = ((total - target)/2);
        vector<vector<int>> dp(nums.size(), vector<int> (nT+1, -1));
        return solve(nums, nT, nums.size()-1, dp);
    }
};