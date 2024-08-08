class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele = nums[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(nums[i] == ele) count++;
            else if(nums[i] != ele && count > 0){
                count--;
            }
            else if(count == 0){
                ele = nums[i];
                count = 1;
            }
        }
        return ele;
    }
};