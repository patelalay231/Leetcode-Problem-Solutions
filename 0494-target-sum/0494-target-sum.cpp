class Solution {
public:
    int helper(vector<int>& nums, int i,int target){
        if(target == 0 && i < 0){
            return 1;
        }
        if(i < 0){
            return  0;
        }
        int plus_sign = helper(nums,i-1,target - nums[i]);
        int neg_sign = helper(nums,i-1,target + nums[i]);
        return plus_sign + neg_sign;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums,n-1,target);
    }
};