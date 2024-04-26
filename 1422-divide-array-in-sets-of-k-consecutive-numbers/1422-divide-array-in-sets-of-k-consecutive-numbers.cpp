class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        for(auto it:hand){
            mp[it]++;
        }
        int n = hand.size();
        if(n%groupSize != 0) return false;
        for(int i=0;i<n;i++){
            if(mp.find(hand[i]) != mp.end()){
                for(int j=0;j<groupSize;j++){
                    if(mp.find(hand[i]+j) == mp.end()){
                        return false;
                    }
                    mp[hand[i]+j]--;
                    if(mp[hand[i]+j] == 0){
                        mp.erase(hand[i]+j);
                    }
                }
            }
        }
        return true;
    }
};