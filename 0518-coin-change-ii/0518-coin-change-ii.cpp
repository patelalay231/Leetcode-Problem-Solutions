class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)prev[i]=1;
        }
        for(int i=1;i<n;i++){
            for(int am=0;am<=amount;am++){
                int nottake=prev[am];
                int take=0;
                if(coins[i]<=am){
                    take=curr[am-coins[i]];
                }
                curr[am]=take+nottake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};