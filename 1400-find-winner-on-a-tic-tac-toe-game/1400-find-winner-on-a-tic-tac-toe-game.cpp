class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3, vector<int>(3,0));
        char turn = 'A';
        int n = moves.size();
        for (int i = 0; i < n; i++) {
            if (turn == 'A') {
                board[moves[i][0]][moves[i][1]] = 1;
                turn = 'B';
            } else {
                board[moves[i][0]][moves[i][1]] = 2;
                turn = 'A';
            }
        }
        for (int i = 0; i < 3; i++) {
            int cntA = 0, cntB = 0;
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 1) {
                    cntA++;
                } else if (board[i][j] == 2) {
                    cntB++;
                }
            }
            if (cntA == 3)
                return "A";
            else if (cntB == 3)
                return "B";
        }
        for (int i = 0; i < 3; i++) {
            int cntA = 0, cntB = 0;
            for (int j = 0; j < 3; j++) {
                if (board[j][i] == 1) {
                    cntA++;
                } else if (board[j][i] == 2) {
                    cntB++;
                }
            }
            if (cntA == 3)
                return "A";
            else if (cntB == 3)
                return "B";
        }
        if ((board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) ||
            (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)) {
            return "A";
        } else if ((board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) ||
                   (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)) {
            return "B";
        } else if (moves.size() != 9) {
            return "Pending";
        }
        return "Draw";
    }
};