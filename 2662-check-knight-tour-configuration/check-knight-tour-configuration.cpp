class Solution {
public:
 bool dfs(int i, int j, int move, vector<vector<int>>& grid, int n) {
    // Out of bounds or wrong move
        if(i < 0 || j < 0 || i >= n || j >= n) return false;

        // If this cell does not match the move number in grid → invalid
        if(grid[i][j] != move) return false;

        // Base case: reached the last move
        if(move == n * n - 1) return true;

        // Try all 8 knight moves
        return dfs(i + 2, j + 1, move + 1, grid, n) ||
               dfs(i - 2, j + 1, move + 1, grid, n) ||
               dfs(i + 1, j - 2, move + 1, grid, n) ||
               dfs(i + 1, j + 2, move + 1, grid, n) ||
               dfs(i - 2, j - 1, move + 1, grid, n) ||
               dfs(i + 2, j - 1, move + 1, grid, n) ||
               dfs(i - 1, j + 2, move + 1, grid, n) ||
               dfs(i - 1, j - 2, move + 1, grid, n);
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(0, 0, 0, grid, n);
    }
};