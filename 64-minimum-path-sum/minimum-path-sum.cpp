class Solution {
public:
    int dp[201][201];
    int m, n;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i >= m || j >= n)
            return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if (i == m - 1 && j == n - 1)
            return dp[i][j] =  grid[i][j];
        if (i == m - 1) { // tum down nhi jaa skte isme row hi khtm ho gyi
            return dp[i][j] = grid[i][j] + dfs(grid, i, j + 1);
        }

        else if (j == n - 1) {
            return dp[i][j] = grid[i][j] + dfs(grid, i + 1, j);
        } else {
            return dp[i][j] = grid[i][j] + min(dfs(grid, i + 1, j), dfs(grid, i, j + 1));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
       memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0);
        
    }
};