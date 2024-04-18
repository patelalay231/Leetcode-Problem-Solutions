class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return SUMARRAY(nums, goal) - SUMARRAY(nums, goal - 1);
    }
    
    int SUMARRAY(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int count = 0, i = 0, j = 0, sum = 0;
        while (i < nums.size()) {
            sum += nums[i]; 
            while (j < nums.size() && sum > goal) {
                sum -= nums[j];
                j++;
            }
            count += i - j + 1;
            i++;
        }
        return count;
    }
};