/*Subsets*/

class Solution {
public:

    void sub(vector<int> &ans, vector<vector<int>> &res, vector<int> &nums, int ind){
        if(ind == nums.size())
            return res.push_back(ans);
        sub(ans,res,nums,ind+1);
        ans.push_back(nums[ind]);
        sub(ans,res,nums,ind+1);
        ans.pop_back();
    }    

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        sub(ans,res,nums,0);
        return res;
    }
};