class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        

        queue<pair<int,int>> q;
        
        // Storing rotten oranges at time 0 
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int min = 0;
        // Rotting neighnour fresh oranges
        while(!q.empty()){
            int n = q.size();
            bool rotten = false;
            for(int i=0;i<n;i++){
                int row = q.front().first;
                int column = q.front().second;
                q.pop();
                if((column-1) >= 0){
                    if(grid[row][column-1] == 1){
                        grid[row][column-1] = 2;
                        q.push({row,column-1});
                        rotten = true;
                    } 
                }
                if((column+1) < c){
                    if(grid[row][column+1] == 1){
                        grid[row][column+1] = 2;
                        q.push({row,column+1});
                        rotten = true;
                    } 
                }
                if((row+1) < r){
                    if(grid[row+1][column] == 1){
                        grid[row+1][column] = 2;
                        q.push({row+1,column});
                        rotten = true;
                    } 
                }
                if((row-1) >= 0){
                    if(grid[row-1][column] == 1){
                        grid[row-1][column] = 2;
                        q.push({row-1,column});
                        rotten = true;
                    } 
                }
            }
            if(rotten) min++;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return min;
    }
};