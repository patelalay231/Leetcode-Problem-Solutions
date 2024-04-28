class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto ele : nums) {
            mp[ele]++;
        } // o(n)
        vector<pair<int, int>> freqMp;
        for (auto it : mp) {
            freqMp.push_back({it.second, it.first});
        } // 0(klogk)
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
        };
        sort(freqMp.begin(), freqMp.end(), cmp);
        vector<int> ans;
        for (auto it : freqMp) {
            ans.push_back(it.second);
            if (ans.size() == k)
                break;
        } // 0(k)
        return ans;
    }
};