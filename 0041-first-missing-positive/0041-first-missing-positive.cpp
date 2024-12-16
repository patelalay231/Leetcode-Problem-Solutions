class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            if(it > 0) mp[it]++;
        }
        int i = 1;
        while(mp[i]) i++;
        return i;
    }
};