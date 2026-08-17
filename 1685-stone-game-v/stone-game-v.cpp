class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, vector<int>&cumSum){
        int score = 0;
        if(dp[i][j] != -1)return dp[i][j];
        for(int mid = i; mid <= j - 1; mid++){
          int leftSum = cumSum[mid] - (i > 0 ? cumSum[i - 1] : 0);
          int rightSum = cumSum[j] - cumSum[mid];
          if(leftSum < rightSum){
            score = max({score, leftSum + solve(i, mid, cumSum)});
          }
          else if(leftSum > rightSum){
             score = max({score, rightSum + solve(mid + 1, j, cumSum)});
          }
          else{
             score = max({score, leftSum + solve(i, mid, cumSum), rightSum + solve(mid + 1, j, cumSum)});
          }
        }
        return dp[i][j] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp, -1, sizeof(dp));
        //cumulative sum 
        vector<int>cum(n);
        cum[0] = stoneValue[0];
        for(int i = 1; i < n; i++){
            cum[i] = cum[i - 1] + stoneValue[i];
        }
        return solve(0, n - 1, cum);
    }
};