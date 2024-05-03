class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // if(g.size() == 0 || s.size() == 0){
        //     return 0;
        // }
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int assign = 0;
        int j = 0;
        int n = g.size();
        int m = s.size();
        for(int i=0;i<n;i++){
            if(j<m && g[i] <= s[j]){
                j++;
                assign++;
            }
        }
        return assign;
    }
};