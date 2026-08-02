class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& piles, int i, int j) {
        if (i > j)
            return 0;

        if(dp[i][j] != -1)return dp[i][j];
        int take = piles[i] - solve(piles, i + 1, j);
        int skip = piles[j] - solve(piles, i, j - 1);

        return dp[i][j] = max(take, skip);
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(piles, 0, piles.size() - 1);
        return ans > 0;
    }
};