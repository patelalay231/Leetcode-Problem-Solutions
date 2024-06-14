typedef pair<int, pair<int, int>> triplet;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        priority_queue<triplet, vector<triplet>, greater<triplet>> pq;
        pq.push({grid[0][0], {0, 0}});
        int rd[] = {-1, 0, 1, 0};
        int cd[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            int depth = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == rows - 1 && c == cols - 1) {
                return depth;
            }

            if (vis[r][c]) continue;
            vis[r][c] = true;

            for (int i = 0; i < 4; ++i) {
                int nr = r + rd[i];
                int nc = c + cd[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !vis[nr][nc]) {
                    pq.push({max(grid[nr][nc], depth), {nr, nc}});
                }
            }
        }
        return -1;
    }
};
