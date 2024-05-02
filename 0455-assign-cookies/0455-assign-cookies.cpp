class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // if(g.size() == 0 || s.size() == 0){
        //     return 0;
        // }
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int assign = 0;
        int j = 0;
        int n = min(s.size(),g.size());
        for(int i=0;i<n;i++){
            while(j<s.size() && s[j] < g[i]){
                j++;
            }
            if(j == s.size()) break;
            assign++;
            j++;
        }
        return assign;
    }
};