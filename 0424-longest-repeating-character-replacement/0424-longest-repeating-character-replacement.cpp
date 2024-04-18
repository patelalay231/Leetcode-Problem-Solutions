class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        for(int i=0;i<n;i++){
            vector<int> hash(26,0);
            int maxFreq = 0;
            for(int j=i;j<n;j++){
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq,hash[s[j]-'A']);
                int diff = (j-i+1) - maxFreq;
                if(diff > k) break;
                else{
                    maxLen = max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
    }
};