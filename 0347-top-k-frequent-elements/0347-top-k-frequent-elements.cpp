class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto ele : nums) {
            mp[ele]++;
        } // o(n)

        // ----- approach 1 -----
        
        // vector<pair<int, int>> freqMp;
        // for (auto it : mp) {
        //     freqMp.push_back({it.second, it.first});
        // } // 0(klogk)
        // auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        // return a.first > b.first;
        // };
        // sort(freqMp.begin(), freqMp.end(), cmp);

        // vector<int> ans;
        // for (auto it : freqMp) {
        //     ans.push_back(it.second);
        //     if (ans.size() == k)
        //         break;
        // } // 0(k)


        // ----- approach 2 -----   

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};