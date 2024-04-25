class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        vector<int> mp(26,0);
        for(char &ch:tasks){
            mp[ch-'A']++;
        }
        int time = 0;

        priority_queue<int> pq;
        for(int it:mp){
            if(it>0){
                pq.push(it);
            }
        }

        while(!pq.empty()){
            
            vector<int> temp;
            for(int i=1;i<=k+1;i++){
                if(!pq.empty()){
                    int ele = pq.top();
                    pq.pop();
                    ele--;
                    temp.push_back(ele);
                }
            }

            for(auto it:temp){
                if(it > 0){
                    pq.push(it);
                }
            }

            if(pq.empty()){
                time += temp.size();
            }
            else{
                time += k+1;
            }
            
        }

        return time;
    }
};