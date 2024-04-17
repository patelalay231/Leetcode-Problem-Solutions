class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                if(mp.find(s[j]) == mp.end()){
                    mp[s[j]] = 1;
                }
                else{
                    break;
                }
            }
            maxLen = max(maxLen,(int)mp.size());   
        }
        return maxLen;
    }
};