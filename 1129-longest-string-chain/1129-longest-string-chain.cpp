#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        return a.size() < b.size();
    }

    bool checkSubseq(string a, string b) {
        int n = a.size();
        int m = b.size();
        if (n != m - 1) {
            return false;
        }
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkSubseq(words[j],words[i]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        return maxi; 
    }
};
