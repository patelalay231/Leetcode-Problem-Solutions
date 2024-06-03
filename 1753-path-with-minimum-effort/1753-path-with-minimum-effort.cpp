class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Initialize distance matrix with infinity, except the starting point (0,0)
        vector<vector<int>> diff(rows, vector<int>(cols, INT_MAX));

        // Define all 4 possible directions
        vector<pair<int, int>> directions = {
            {1, 0},   // Right
            {-1, 0},  // Left
            {0, 1},   // Down
            {0, -1},  // Up
        };

        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        diff[0][0] = 0;
        
        int maxDiff = INT_MIN;
        while(!st.empty()){
            auto it = st.begin();
            int currentEffort = it->first;
            int i = it->second.first;
            int j = it->second.second;
            st.erase(it);
            
            for(auto& direction : directions) {
                int ni = i + direction.first;
                int nj = j + direction.second;

                // Check if the new position is within bounds and is not blocked
                if(ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                    int newEffort = max(currentEffort, abs(heights[ni][nj] - heights[i][j]));
                    if(newEffort < diff[ni][nj]) {
                        // If there's a better path, update the distance and insert into the set
                        if(diff[ni][nj] != INT_MAX) {
                            st.erase({diff[ni][nj], {ni, nj}});
                        }
                        diff[ni][nj] = newEffort;
                        st.insert({newEffort, {ni, nj}});
                    }
                }
            }
        }
        return diff[rows-1][cols-1];
    }
};