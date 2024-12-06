class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int mini = 0,maxi = 0,n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 1) mini = i;
            else if(nums[i] == n) maxi = i;
        }

        int steps = mini + n-maxi-1;
        if(maxi < mini) steps-=1;
        return steps;

    }
};