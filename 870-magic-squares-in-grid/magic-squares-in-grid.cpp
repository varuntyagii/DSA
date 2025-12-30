class Solution {
public:
    bool isMatch(vector<vector<int>>& grid, int r, int c) {
        // unique number
        //  1 to 9
        // sum = 15
        unordered_set<int> st;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || st.count(num)) {
                    return false;
                } else {
                    st.insert(num);
                }
            }
        }
        //row

        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != 15) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != 15) {
                return false;
            }
        }

        // for r to l digonal
        
            if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15) {
                return false;
            }
        
        // for l to r digonal
       
            if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15) {
                return false;
            }
        
        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isMatch(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};