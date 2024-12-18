class Solution {
public:

    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(auto it : points){
            unordered_map<double,int> mp;
            for(auto ij:points){
                if(it != ij){
                    int numerator = ij[1] - it[1];
                    int denominator = ij[0] - it[0];
                    // if denominator is zero then it's straight_line
                    if(denominator == 0){
                        mp[INT_MAX]++;
                    }
                    else{
                        mp[numerator/(double)denominator]++;
                    }
                }
            }
            for(auto it:mp){
                ans = max(ans,it.second+1);
            }
        }
        return ans;
    }
};