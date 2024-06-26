class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mp;
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : hand) {
            mp[it]++;
            if(mp[it] == 1){
                pq.push(it);
            }
        }
        while (!pq.empty()) {
            int ele = pq.top();
            for (int i = 0; i < groupSize; i++) {
                if (mp.find(ele + i) == mp.end()) {
                    return false;
                }
                mp[ele + i]--;
                if (mp[ele + i] == 0) {
                    pq.pop();
                    mp.erase(ele + i);
                }
            }
        }
        return true;
    }
};