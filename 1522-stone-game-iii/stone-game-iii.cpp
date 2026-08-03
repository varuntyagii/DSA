class Solution {
public:
    // int dp[50001];
    vector<int>dp;
    int solve(vector<int>& stone, int i) {
        int n = stone.size();
        int res = INT_MIN;
        if(dp[i] != -1)return dp[i];
        if (i >= stone.size())
            return 0;
        res = max(res, stone[i] - solve(stone, i + 1));
         if (i + 1 < n) res =
            max(res, stone[i] + stone[i + 1] - solve(stone, i + 2));
         if (i + 2 < n) res = max(
            res, stone[i] + stone[i + 1] + stone[i + 2] - solve(stone, i + 3)); // Alice(i+1,i+2, i+3) - solve(bob) 
        return dp[i] = res; 
    }
    string stoneGameIII(vector<int>& stone) {
        // memset(dp, -1, sizeof(dp));
         int n = stone.size();
        dp.assign(n + 1, -1);
        int val = solve(stone, 0);
        if (val > 0)
            return "Alice";
        else if (val < 0)
            return "Bob";
        else
            return "Tie";
    }
};