#include <vector>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Helper function to perform BFS and check if a path exists within the given max effort
        auto canReachEnd = [&](int maxEffort) -> bool {
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            
            vector<pair<int, int>> directions = {
                {1, 0},   // Right
                {-1, 0},  // Left
                {0, 1},   // Down
                {0, -1},  // Up
            };

            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                
                if (i == rows - 1 && j == cols - 1) {
                    return true;
                }

                for (auto& direction : directions) {
                    int ni = i + direction.first;
                    int nj = j + direction.second;

                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && !visited[ni][nj]) {
                        int effort = abs(heights[ni][nj] - heights[i][j]);
                        if (effort <= maxEffort) {
                            visited[ni][nj] = true;
                            q.push({ni, nj});
                        }
                    }
                }
            }
            return false;
        };

        // Binary search for the minimum possible maximum effort
        int left = 0, right = 1e6, result = 1e6;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReachEnd(mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
