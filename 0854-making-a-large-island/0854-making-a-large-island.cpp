#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = findUPar(parent[u]);
    }

    int maxSize() {
        int maxi = INT_MIN;
        for (auto it : size) {
            maxi = max(it, maxi);
        }
        return maxi;
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
            return;
        } else if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int getSize(int u) {
        int root = findUPar(u);
        return size[root];
    }
};

class Solution {
public:
    bool isValid(int adjr, int adjc, int n) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Directions for adjacency (up, right, down, left)
        vector<int> adjr = {-1, 0, 1, 0};
        vector<int> adjc = {0, 1, 0, -1};

        // Connect adjacent 1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int nr = adjr[k] + i;
                        int nc = adjc[k] + j;
                        if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                            int adjNode = nr * n + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        // Find the largest connected component
        int maxi = ds.maxSize();

        // Try flipping each 0 to 1 and see if we get a larger island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    for (int k = 0; k < 4; k++) {
                        int nr = adjr[k] + i;
                        int nc = adjc[k] + j;
                        if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                            uniqueIslands.insert(ds.findUPar(nr * n + nc));
                        }
                    }
                    int potentialSize = 1;  // Starting with the flipped cell itself
                    for (int root : uniqueIslands) {
                        potentialSize += ds.getSize(root);
                    }
                    maxi = max(maxi, potentialSize);
                }
            }
        }

        return maxi;
    }
};
