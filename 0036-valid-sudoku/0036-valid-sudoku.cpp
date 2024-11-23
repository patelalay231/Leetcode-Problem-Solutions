class Solution {
public:
    bool check(vector<vector<char>>& board, int r, int c, char k) {
        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == k) return false; // Check row
            if (board[i][c] == k) return false; // Check column
        }
        
        // Check 3x3 sub-box
        int row = (r / 3) * 3;
        int col = (c / 3) * 3;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == k) return false;
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char num = board[i][j];
                    board[i][j] = '.'; // Temporarily remove the number for validation
                    if (!check(board, i, j, num)) {
                        return false;
                    }
                    board[i][j] = num; // Restore the number
                }
            }
        }
        return true;
    }
};
