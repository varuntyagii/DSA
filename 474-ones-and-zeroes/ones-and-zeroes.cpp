class Solution {
public:
    // m for 0 and n for 1
    int dp[101][101][601];
    int solve(vector<pair<int, int>>&count, int m, int n, int i){
        if(i >= count.size() || (m == 0 && n == 0))return 0;
        if(dp[m][n][i] != -1)return dp[m][n][i];
        int take = 0;
        if(count[i].first <= m && count[i].second <= n){
            take = 1 + solve(count, m - count[i].first, n - count[i].second, i + 1);
        }
        int skip = solve(count, m, n, i + 1);
        return dp[m][n][i] = max(skip, take);
    }
    int findMaxForm(vector<string>& str, int m, int n) {
        int  k = str.size();
        vector<pair<int, int>>count(k);
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < k; i++){
            int count0 = 0;
            int count1 = 0;
            for(auto ch: str[i]){
                if(ch == '0'){
                    count0++;
                }
                else{
                    count1++;
                }
            }
            count[i] = {count0, count1};
        }
        return solve(count, m, n, 0);
    }
};