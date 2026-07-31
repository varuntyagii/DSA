class Solution {
public:
    int n, m;
    int dp[101][101];
    int solve(vector<vector<int>>& mat, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 1) {
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if (i == n - 1 && j == m - 1)
            return 1;

        int down = solve(mat, i + 1, j);
        int right = solve(mat, i, j + 1);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        memset(dp, -1, sizeof(dp));
      return  solve(mat, 0, 0);
    }
};