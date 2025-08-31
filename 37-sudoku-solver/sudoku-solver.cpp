
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') { // empty cell
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isValid(board, row, col, ch)) {
                            board[row][col] = ch;  // place number

                            if(solve(board)) return true; // recurse

                            board[row][col] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number, backtrack
                }
            }
        }
        return true; // all filled
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            // check row
            if(board[row][i] == ch) return false;
            // check column
            if(board[i][col] == ch) return false;
            // check 3x3 grid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if(board[subRow][subCol] == ch) return false;
        }
        return true;
    }
};