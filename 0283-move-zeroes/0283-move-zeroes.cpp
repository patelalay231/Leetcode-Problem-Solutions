class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zero_idx = -1;
        for(int i=0;i<n;i++){
            if(nums[i] != 0 && zero_idx != -1){
                swap(nums[i],nums[zero_idx]);
                zero_idx++;
            }
            else if(nums[i] == 0 && zero_idx == -1){
                zero_idx = i;
            }
        }
    }   
};