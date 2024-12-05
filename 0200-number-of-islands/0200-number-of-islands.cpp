class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j, int n, int m) {
        vector<int> rd = {-1, 0, 1, 0};
        vector<int> cd = {0, -1, 0, 1};
        visited[i][j] = 1;

        for (int d = 0; d < 4; d++) {
            int ni = i + rd[d];
            int nj = j + cd[d];
            // Check boundaries and ensure the cell is land ('1') and not visited
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && visited[ni][nj] == 0) {
                dfs(grid, visited, ni, nj, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    dfs(grid, visited, i, j, n, m);
                    islands++;
                }
            }
        }

        return islands;
    }
};
