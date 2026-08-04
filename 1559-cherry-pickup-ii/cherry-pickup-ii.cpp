class Solution {
public:
    int m, n;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
        int cherries = 0;

        if (c1 == c2)
            cherries = grid[row][c1];
        else
            cherries = grid[row][c1] + grid[row][c2];

        if (row == m - 1)
            return cherries;

        if(dp[row][c1][c2] != -1)return dp[row][c1][c2];
        int ans = -1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newrow = row + 1;
                int newcol1 = c1 + i;
                int newcol2 = c2 + j;

                if (newcol1 >= 0 && newcol1 < n && newcol2 >= 0 &&
                    newcol2 < n) {
                    ans = max(ans, solve(grid, newrow, newcol1, newcol2));
                }
            }
        }
        return dp[row][c1][c2] = ans + cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // dp.assign(m + 1, vector<int>(n + 1, - 1));
        dp.assign(m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solve(grid, 0, 0, n - 1);
    }
};