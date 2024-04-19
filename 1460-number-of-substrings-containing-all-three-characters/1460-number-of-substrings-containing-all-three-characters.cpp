class Solution {
public:
    int solve(string s,int k){
        int n = s.length();
        int subs = 0;
        int l = 0,r = 0;
        unordered_map<char,int> mp;
        while(r < n){
            mp[s[r]]++;
            while(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if(mp.size() <= k) subs += r - l + 1;
            r++;
        }
        return subs;
    }
    int numberOfSubstrings(string s) {
        return solve(s,3) - solve(s,2);
    }
};