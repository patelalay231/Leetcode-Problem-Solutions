class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<nums.size();i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int non_pick = prev;
            int curri = max(pick,non_pick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};