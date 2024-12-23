class Solution {
public:
    int solve(int n,
               vector<int>& leftrow, vector<int>& lowerDiag,
               vector<int>& upperDiag, int col) {
        if (col == n) {
            return 1;
        }
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && lowerDiag[row + col] == 0 &&
                upperDiag[n - 1 + col - row] == 0) {
                leftrow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;
                cnt += solve(n, leftrow, lowerDiag, upperDiag, col + 1);
                leftrow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
    
        vector<int> leftrow(n, 0), lowerDiag(2 * n - 1, 0),upperDiag(2 * n - 1, 0);
        return solve( n, leftrow, lowerDiag, upperDiag, 0);
    }
};