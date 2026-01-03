class Solution {
public:
    int dp[505][205];

    int solve(vector<int>& s, int i, int end, int n) {
        if (n == 0) return 0;
        if (i > end) return -1e9;
        if (dp[i][n] != -1) return dp[i][n];

        int take = s[i] + solve(s, i + 2, end, n - 1);
        int skip = solve(s, i + 1, end, n);

        return dp[i][n] = max(take, skip);
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int n = k / 3;

        memset(dp, -1, sizeof(dp));
        int case1 = solve(slices, 0, k - 2, n); // last excluded

        memset(dp, -1, sizeof(dp));
        int case2 = solve(slices, 1, k - 1, n); // first excluded

        return max(case1, case2);
    }
};
