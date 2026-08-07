class Solution {
public:
    int dp[10001][13];
    int solve(vector<int>& coins, int amount, int i) {
        if (amount == 0)
            return 0;
        // if(i >= coins.size())return le9;
        if (amount < 0) {
            return 1e9; // imposible state coins[i] = 5 amount = 3 agr 0 diya
                        // toh 1 + 0 agr -1 toh 1 + (-1) = 0
        }
        if(dp[amount][i] != -1){
           return dp[amount][i];
        }
        if (i == coins.size()) {
            return 1e9;
        }

        int take = 1 + solve(coins, amount - coins[i], i);

        int skip = solve(coins, amount, i + 1);
        return dp[amount][i] = min(skip, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount, 0);
        return ans == 1e9 ? -1 : ans;
    }
};