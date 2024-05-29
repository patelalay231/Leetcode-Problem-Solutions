class Solution {
public:

    void dfs(vector<vector<char>>& board,int rows,int cols ,int i, int j,vector<vector<int>>& isConnectedToEdge){

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(auto it:dir){
            int ni = it.first + i;
            int nj = it.second + j;

            if(ni >=0 && ni < rows && nj >= 0 && nj < cols && !isConnectedToEdge[ni][nj] && board[ni][nj] == 'O'){
                isConnectedToEdge[ni][nj] = 1;
                dfs(board,rows,cols,ni,nj,isConnectedToEdge);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> isConnectedToEdge(rows,vector<int>(cols,0));

        for(int i=0;i<rows;i++){
            if(board[i][0] == 'O' && !isConnectedToEdge[i][0]){
                dfs(board,rows,cols,i,0,isConnectedToEdge);
            }
            if(board[i][cols-1] == 'O' && !isConnectedToEdge[i][cols-1]){
                dfs(board,rows,cols,i,cols-1,isConnectedToEdge);
            }
        }

        for(int i=0;i<cols;i++){
            if(board[0][i] == 'O' && !isConnectedToEdge[0][i]){
                dfs(board,rows,cols,0,i,isConnectedToEdge);
            }
            if(board[rows-1][i] == 'O' && !isConnectedToEdge[rows-1][i]){
                dfs(board,rows,cols,rows-1,i,isConnectedToEdge);
            }
        }


        for(int i=1;i<rows-1;i++){
            for(int j=1;j<cols-1;j++){
                if(board[i][j] == 'O' && !isConnectedToEdge[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};