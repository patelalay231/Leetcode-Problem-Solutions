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
        
        // Initialize distance matrix with infinity, except the starting point (0,0)
        vector<vector<int>> diff(rows, vector<int>(cols, INT_MAX));
        diff[0][0] = 0;  // Starting point effort is 0

        // Define all 4 possible directions
        vector<pair<int, int>> directions = {
            {1, 0},   // Right
            {-1, 0},  // Left
            {0, 1},   // Down
            {0, -1},  // Up
        };

        // Use a priority queue to act as a min-heap for Dijkstra's algorithm; stores the effort and coordinates
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()) {
            auto [currentEffort, pos] = pq.top();
            int i = pos.first;
            int j = pos.second;
            pq.pop();

            // If we reach the bottom-right cell, return the effort
            // if(i == rows - 1 && j == cols - 1) {
            //     return currentEffort;
            // }

            for(auto& direction : directions) {
                int ni = i + direction.first;
                int nj = j + direction.second;

                // Check if the new position is within bounds
                if(ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                    // Calculate the effort to move to the new cell
                    int newEffort = max(currentEffort, abs(heights[ni][nj] - heights[i][j]));

                    // If the new calculated effort is better, update and insert into the priority queue
                    if(newEffort < diff[ni][nj]) {
                        diff[ni][nj] = newEffort;
                        pq.push({newEffort, {ni, nj}});
                    }
                }
            }
        }

        // If we exit the loop without finding a path, return -1 (though in a valid grid, this won't happen)
        return diff[rows-1][cols-1];
    }
};
