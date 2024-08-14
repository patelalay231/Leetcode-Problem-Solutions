class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxSum = 0;
        for(int i=0;i<n;i+=2){
            maxSum += min(nums[i],nums[i+1]);
        }
        return maxSum;
    }
};