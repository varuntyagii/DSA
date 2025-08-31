class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char d) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == d) return false;  // check row
            if (board[i][col] == d) return false;  // check col
        }

        int start_i = (row / 3) * 3;
        int start_j = (col / 3) * 3;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[start_i + k][start_j + l] == d) {
                    return false; // check 3x3 box
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, i, j, d)) {
                            // place number
                            board[i][j] = d;

                            // recurse
                            if (solve(board)) return true;

                            // undo if recursion fails
                            board[i][j] = '.';
                        }
                    }
                    return false; // no number worked for this cell
                }
            }
        }
        return true; // filled all cells
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
