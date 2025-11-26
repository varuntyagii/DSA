class Solution {
public:
    int m, n;
    int Mod = 1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(int i, int j, int currSum, vector<vector<int>>& grid, int k) {
        if(i >= n || j >= m) return 0;

        if(i == n - 1 && j == m - 1)
            return ((currSum + grid[i][j]) % k == 0);

        if(dp[i][j][currSum] != -1) 
            return dp[i][j][currSum];

        int next = (currSum + grid[i][j]) % k;

        int right = solve(i + 1, j, next, grid, k);
        int down  = solve(i, j + 1, next, grid, k);

        return dp[i][j][currSum] = (right + down) % Mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return solve(0, 0, 0, grid, k);
    }
};
