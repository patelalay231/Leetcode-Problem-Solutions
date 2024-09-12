/*Subsets*/

class Solution {
public:

    void sub(vector<int> &ans, vector<vector<int>> &res, vector<int> &nums, int ind){
        
        res.push_back(ans);

        for(int i=ind;i<nums.size();i++){
            ans.push_back(nums[i]);
            sub(ans,res,nums,i+1);
            ans.pop_back();
        }

    }    

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        sub(ans,res,nums,0);
        return res;
    }
};