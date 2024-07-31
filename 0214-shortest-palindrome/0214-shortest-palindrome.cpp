class Solution {
public:
    vector<int> findLPS(string s){
        int n = s.size();
        vector<int> lps(n,0);
        int i = 1,prevLps = 0;
        while(i < n){
            if(s[i] == s[prevLps]){
                lps[i] = prevLps + 1;
                prevLps++;
                i++;
            }
            else{
                if(prevLps == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    prevLps = lps[prevLps-1];
                }
            }
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        vector<int> lps;
        string revS = s;
        reverse(revS.begin(),revS.end());

        string temp = s + '$' + revS;
        lps = findLPS(temp);
        string subStr = s.substr(lps.back());
        reverse(subStr.begin(),subStr.end());
        return subStr + s;
    }
};