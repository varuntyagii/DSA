class Solution {
public:
    int dp[1001][1001];
    int solve(string& s1, string &s2, int i, int j){
        int m = s1.size();
        int n = s2.size(); 

        if(j >= n && i >= m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(j >= n){
            return dp[i][j] = s1[i] + solve( s1, s2, i + 1, j);
        }
        
         if(i >= m){
                return dp[i][j] = s2[j] + solve( s1, s2, i, j + 1);
        }
         if(s1[i] == s2[j]){
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }
        int del_s1_i =  s1[i] + solve(s1, s2, i + 1, j);
        int del_s2_j =  s2[j] + solve(s1, s2, i, j + 1);
        return dp[i][j] = min(del_s1_i, del_s2_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};