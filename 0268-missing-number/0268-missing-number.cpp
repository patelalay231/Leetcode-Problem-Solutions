class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = (n * (n+1))/2;
        long long curr_sum = 0;
        for(int i=0;i<n;i++){
            curr_sum += nums[i];
        }
        return total_sum - curr_sum;
    }
};