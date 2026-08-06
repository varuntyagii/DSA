class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(amount + 1, 1e9));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {

            dp[i][0] = 0;

            for (int j = 1; j <= amount; j++) {

                // Not Take
                dp[i][j] = dp[i - 1][j];

                // Take
                if (j >= coins[i - 1]) {
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i][j - coins[i - 1]]);
                }
            }
        }

        return dp[n][amount] == 1e9 ? -1 : dp[n][amount];
    }
};