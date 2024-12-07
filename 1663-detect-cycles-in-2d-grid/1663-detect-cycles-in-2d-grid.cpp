#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int n, int m, int i, int j, int pi, int pj, char parent) {
        // Directions for up, left, down, and right
        int rd[4] = {-1, 0, 1, 0};
        int cd[4] = {0, -1, 0, 1};

        // Mark current cell as visited
        visited[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + rd[k];
            int nj = j + cd[k];

            // Check bounds and if the adjacent cell has the same character
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == parent) {
                // Skip the parent cell
                if (ni == pi && nj == pj) continue;

                // If the cell is already visited, a cycle exists
                if (visited[ni][nj] == 1) {
                    return true;
                }

                // Continue DFS
                if (dfs(grid, visited, n, m, ni, nj, i, j, parent)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Visited grid to track visited cells
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0) {
                    // Start a DFS search
                    if (dfs(grid, visited, n, m, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
