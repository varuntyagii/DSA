class Solution {
public:
    int n;
    int m;
    int dp[301][301];
    int solve(vector<vector<int>>& mat, int i, int j){
        if(i >= n || j >= m || mat[i][j] == 0){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int right = solve(mat, i + 1, j);
        int dig   = solve(mat, i + 1, j + 1);
        int down = solve(mat, i,     j + 1);
        return dp[i][j] = 1 + min({right, dig, down});
    }
    int countSquares(vector<vector<int>>& mat) {
         n = mat.size();
         m = mat[0].size();
        int result = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 if(mat[i][j] == 1){
                    result += solve(mat, i, j);
                 }
            }
        }
        return result;

    }
};