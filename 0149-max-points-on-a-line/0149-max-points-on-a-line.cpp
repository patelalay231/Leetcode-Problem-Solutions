class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n; // If there are 2 or fewer points, all points are on the same line.
        
        int max_points = 1;
        
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slope_count;
            int overlap = 0, vertical = 0, current_max = 0;
            
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    // Same point (overlapping)
                    ++overlap;
                } else if (dx == 0) {
                    // Vertical line
                    ++vertical;
                    current_max = max(current_max, vertical);
                } else {
                    // Compute the slope in reduced form
                    int gcd_val = gcd(dx, dy);
                    dx /= gcd_val;
                    dy /= gcd_val;
                    
                    // Handle direction consistency
                    string slope = to_string(dx) + "/" + to_string(dy);
                    ++slope_count[slope];
                    current_max = max(current_max, slope_count[slope]);
                }
            }
            // Add the overlapping points and the current point to the count
            max_points = max(max_points, current_max + overlap + 1);
        }
        return max_points;
    }
    
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
