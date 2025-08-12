class Solution {
public:
    int modulo = 1e9+7; //10^9 + 7
    int dp[301][301];
    int solve(int n, int num, int x){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        if(pow(num, x) > n){
            return 0;
        }
        if(dp[n][num] != -1){
            return dp[n][num];
        }
        int take = solve(n - pow(num, x), num + 1, x);
        int skip = solve(n, num + 1, x);
        return dp[n][num] = (take + skip) % modulo;
    }
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp)); // initialize with -1
        return solve(n, 1, x);
    }
};