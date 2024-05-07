class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        int n = nums.size();
        if(n == 1) return true;
        int i = 1;
        while(maxJump){
            if(i == n-1) return true;
            maxJump--;
            maxJump = max(maxJump,nums[i]);
            i++;
        }
        return false;
    }
};