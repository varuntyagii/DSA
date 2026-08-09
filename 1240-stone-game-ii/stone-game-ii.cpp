class Solution {
public:
    int n;
    int dp[2][101][101];
    int solve(vector<int>& p, int person, int i, int M){

        if(i >= n)return 0;
        if(dp[person][i][M] != -1)return dp[person][i][M];
        int stone = 0;
        int result = (person == 1) ? -1:  INT_MAX;
        for(int x = 1; x <= min(2*M, n - i); x++){
             stone += p[x + i - 1];
            if(person == 1){
                result = max(result, stone + solve(p, 0, i + x, max(M, x)));
            }
            else{
                 result = min(result,  solve(p, 1, i + x, max(M, x)));

            }
        }
        return dp[person][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
     return solve(piles, 1, 0, 1);
    }
};