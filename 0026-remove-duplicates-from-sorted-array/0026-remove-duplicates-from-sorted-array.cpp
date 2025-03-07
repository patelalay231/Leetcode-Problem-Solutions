class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int index = 0;
        for(int i=1;i<len;i++){
            if(nums[i] != nums[index]){
                nums[++index] = nums[i];
            }
        }
        return ++index;
    }
};