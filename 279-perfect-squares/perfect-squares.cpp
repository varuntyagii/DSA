class Solution {
public:
    int dp[100000];
    int solve(int n){
        if( n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int minVal = INT_MAX;
        for(int i = 1; i * i <= n; i++){
            int ans = 1 + solve(n - i * i);
          dp[n] =  minVal = min(minVal, ans);
        }
        return dp[n];
    }
    int numSquares(int n) {
        
        if(n == 0){
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};