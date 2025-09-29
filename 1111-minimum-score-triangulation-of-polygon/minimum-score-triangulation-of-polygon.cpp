class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, vector<int>& val) {
        int result = INT_MAX;
        if (j - i + 1 < 3) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for (int k = i + 1; k < j; k++) {
            int wt = solve(i, k, val) + val[i] * val[j] * val[k] + solve(k, j, val);
            result = min(result, wt);
        }
        return dp[i][j] = result;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, values);
    }
};