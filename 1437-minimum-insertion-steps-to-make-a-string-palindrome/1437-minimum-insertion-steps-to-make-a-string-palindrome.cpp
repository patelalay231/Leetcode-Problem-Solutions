class Solution {
public:
    int minInsertions(string s) {
        // n-len(l c palindromic subseq).
        int n=s.size();
        string s1=s;
        reverse(s.begin(), s.end());
        string s2=s;
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (s1[i-1]==s2[j-1]){
                    curr[j]=prev[j-1]+1;
                }else{
                    curr[j]=max(curr[j-1], prev[j]);
                }
            }prev=curr;
        }
        int palin=prev[n];
        int ans=n-palin;
        return ans;
    }
};